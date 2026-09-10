## Developer Notes — `athan.yaml` and internals

This file is meant for people who want to change the logic or port the idea to slightly different hardware. It assumes you already read the top‑level `README.md`.

---

### High‑level architecture

- **Platform:** `esp8266` with `board: d1_mini`.
- **ESPHome components used:**
  - `dfplayer` over `uart` for audio playback.
  - `ssd1306_i2c` (128×64) for the UI.
  - `time:` `sntp` for wall‑clock time.
  - `http_request` for JSON and firmware metadata fetching.
  - `api`, `ota`, `wifi`, `captive_portal`.
- **Logic location:** Almost all behaviour lives in inline C++ `lambda`s inside `globals`, `script`, `binary_sensor` handlers, and the `interval` / `time` triggers in `athan.yaml`.

At boot, the firmware restores persisted settings (location, volume, chosen Athan file), applies the saved timezone, and, once SNTP is valid, loads the correct prayer JSON for the current day and location.

---

### Important globals

Some of the key globals in `athan.yaml`:

- `volume_level` (int, persisted) – 0–100% volume, mapped to DFPlayer’s 0–30 range on boot and whenever it changes.
- `athan_file_index` (int, persisted) – Athan choice `k` = 1–10. The regular recording is file `athan_file_first - 1 + k`, the Fajr-wording recording is file `fajr_file_first - 1 + k` (see the `substitutions:` block).
- `htick_file_index` (int, persisted) – DFPlayer file number to play at the top of each hour (0 = disabled).
- `athan_enabled[7]` (bool array, persisted, all `true`) – per-prayer athan ON/OFF, indexed like `prayer_hours` (0 Fajr, 3 Dhuhr, 4 Asr, 5 Maghrib, 6 Isha; 1 and 2 unused).
- `mute_index` (int) – cursor inside the Athan On/Off submenu (0–4 prayers, 5 = Done).
- `selected_location_index` (int, persisted) – index into the Location select's `options:` list.
- `selected_location_tz` (string, persisted) – POSIX TZ string (for example `PST8PDT,M3.2.0,M11.1.0`).
- `prayer_hours[7]` / `prayer_minutes[7]` – daily prayer schedule as parsed from JSON.
- `prayer_times_day` / `prayer_times_year` – day‑of‑year and year for which the above arrays are valid.
- `next_prayer_index`, `next_prayer_hour`, `next_prayer_minute` – computed by `compute_next_prayer` and used by the display and tick logic.
- `athan_playing` – tracks whether DFPlayer is currently playing the Athan.
- `ui_mode`, `ui_menu_index`, `athan_index`, `htick_index`, `location_index` – all used to drive the small menu system.

Several other globals are used only for internal bookkeeping or features that are intentionally not documented in the user‑facing README.

---

### Main scripts and flows

#### `refresh_prayer_times_if_needed`

- Called after Wi‑Fi connection and periodically.
- Checks if we have ever loaded prayer times (`loaded_prayer_times_once`).
- If not, calls `load_prayer_times`.
- If the stored day/year no longer match `now()`, marks the cache as stale and reloads.
- After loading, calls `compute_next_prayer`, `log_prayers`, and `update_display`.

#### `load_prayer_times`

- Builds a URL of the form:

  `http://rawcdn.githack.com/et7ad/esp_athan/master/docs/athantimes/<location>/<year>/<DDD>.json`

  using `selected_location_index`, `sntp_time.now().year`, and `day_of_year`.
- Fetches JSON via `http_request.get` with a small buffer and a hard maximum size.
- Trims everything before the first `{` and after the last `}` to remove noise.
- Parses into an `ArduinoJson` `JsonDocument`.
- Extracts `fajr`, `sunrise`, `doha`, `dhuhar`, `asr`, `maghrib`, `isha` as strings, strips spaces, and fills `prayer_hours`/`prayer_minutes`.
- Performs small PM adjustments (e.g. if Dhuhr hour `< 9`, add 12; for Asr, Maghrib, Isha ensure hours are in the afternoon).
- Sets `prayer_times_day` / `prayer_times_year` to the current day and year and marks `loaded_prayer_times_once = true`.

#### `compute_next_prayer`

- Uses the current time from `sntp_time` and linearly scans the 7 prayer entries.
- First entry that is still in the future becomes `next_prayer_index` and sets `next_prayer_hour` / `next_prayer_minute`.
- If all 7 are in the past, tomorrow’s Fajr is considered the “next” prayer.
- Some additional internal scheduling is done here to prepare extra behaviour around Fajr.

#### `make_athan`

- Sets `athan_playing = true` and stops any web preview.
- Plays the regular recording for the current choice, or the Fajr-wording recording (`fajr_file_first - 1 + k`) when `current_athan_prayer_index == 0`. The tick sets that index *before* executing the script.
- Turns the built‑in LED on for 5 minutes, then off, and marks `athan_playing = false` again.

#### Shared audio scripts

- `silence_audio` – stops the DFPlayer, the debounced `dfp_play`, and `web_preview`, clears `athan_playing`, refreshes the display. Used by both buttons and the web **Stop Audio** button.
- `apply_volume` – clamps `volume_level` and maps 0–100 % to the DFPlayer's 0–30. Used at boot, by the Volume menu and by the web slider.
- `web_preview` – plays `dfp_pending_file` for 20 s and then stops (unless a real athan started meanwhile). Used by the web selects and the Preview Fajr button.
- `sync_web_state` – publishes the selects, the volume number and the text sensors from the globals, only when a value changed. Runs from its own `interval: 1s` entry (not from inside `update_display`), so the publish → API/web callbacks always start from the shallow main-loop stack; the ESP8266 loop stack is only ~4 KB and `update_display` is sometimes reached from deep inside HTTP callbacks. Its format strings use `PSTR`/`snprintf_P` so they live in flash.

#### Per‑second tick (`interval: 1s`)

- Ensures the persisted timezone is applied once when SNTP time becomes valid.
- Skips work until prayer times are successfully loaded.
- Checks whether the current time has passed `next_prayer_hour` / `next_prayer_minute` (with some care around Isha and rollover).
- When that condition is met and the prayer is a main prayer with `athan_enabled[i]` true, sets `current_athan_prayer_index` and triggers `make_athan`. Sunrise, Doha and prayers turned OFF only log; in every case it recomputes the next prayer and updates the display.

#### Display update (`update_display`)

- Clears the OLED and draws either:
  - The menu views (main menu, Athan selection, hourly tick selection, location preview, volume), or
  - The normal view (current time/date, next prayer, and remaining time).
- Includes some small icons and Wi‑Fi indication logic.
- Also enforces menu timeout (after ~60 seconds of inactivity it resets `ui_mode` to 0 and stops any preview audio).

---

### Menu and button handling

- Two GPIO buttons are defined as binary sensors with `INPUT_PULLUP` and `inverted: true`.
- Their `on_press` handlers are implemented in C++ to keep the state machine compact.

Rough behaviour:

- **Normal mode** (`ui_mode == 0`):
  - Select: if Athan is playing, stops it; otherwise enters main menu and plays a small click sound.
  - Next: acts like a “silence” button if Athan is playing, otherwise a no‑op except for a display refresh.

- **Main menu mode** (`ui_mode == 1`):
  - Next: advances `ui_menu_index` (0–8: Athan, Athan On/Off, Hourly Tick, Location, Update, Volume, Info, Cancel, Q) and updates the OLED. Menu indices are not persisted, so the order can change between versions.
  - Select: dispatches based on the current index to enter the relevant submenu or perform actions such as starting an update check.

- **Submenus** (`ui_mode`):

  | `ui_mode` | Screen | Next | Select |
  |---|---|---|---|
  | 2 | Athan audio | next recording (preview) | store `athan_file_index`, exit |
  | 3 | Hourly tick | next tick (preview) | store `htick_file_index`, exit |
  | 4 | Location | next key (preview) | fetch TZ, store, exit |
  | 5 | Volume | −10 % (wraps) | exit |
  | 6 | Athan On/Off | next of Fajr, Dhuhr, Asr, Maghrib, Isha, Done | toggle `athan_enabled[...]` and stay; on Done exit |
  | 7 | Info (version, IP, `athan.local`) | nothing | exit |

  Helper indices (`athan_index`, `htick_index`, `location_index`, `mute_index`) do not touch persisted values until the user presses Select.

This design tries to keep actual writes to persisted globals limited to clear confirmation points so accidental button presses are less likely to store half‑finished state.

---

### JSON layout and adding locations

See the main README for the user‑facing explanation. From the firmware side:

- The location keys live in exactly one place: the `options:` list of the `web_location_select` select in `athan.yaml`. `load_prayer_times`, `change_location_handler`, the Location menu and the web page all read it through `id(web_location_select).at(i)`.
- `selected_location_index` is the persisted index; `location_index` is used as a “preview” index while the location submenu is open (and is what the web select writes before calling `change_location_handler`).

Typical steps to add a new mosque:

1. Create `docs/timezones/<newkey>.json` with a `TZ` string.
2. Generate `/<newkey>/<year>/<DDD>.json` for every day of the year.
3. Replace one of the `masjidN` placeholders in the `web_location_select` `options:` with `<newkey>`. Never insert or reorder: the index is persisted on every deployed device.
4. Update the README table (section 4.4), rebuild and flash.

If you prefer not to fork this repo, you can instead mirror the same JSON layout in your own repo and point the URLs to it, as described in the README.

---

### DFPlayer mapping and SD‑card

The DFPlayer is configured via:

```yaml
uart:
  tx_pin: GPIO1
  rx_pin: GPIO3
  baud_rate: 9600

dfplayer:
  id: dfp
```

All file numbers come from the `substitutions:` block at the top of the YAML, so the layout is changed in one place:

| Substitution | Value | Meaning |
|---|---|---|
| `athan_file_first` | 1 | A1–A10 → files 1–10, regular athans; choice `k` → file `athan_file_first - 1 + k` |
| `htick_file_first` | 11 | B1–B10 → files 11–20, hourly ticks; tick `t` → file `htick_file_first - 1 + t` |
| `tone_volume_file` | 22 | volume feedback tone |
| `tone_click_file` | 23 | menu click |
| `quyam_file_first` / `quyam_file_last` | 25 / 34 | D1–D10, picked at random by `run_quyam` |
| `fajr_file_first` | 35 | F1–F10 → files 35–44, Fajr-wording athans; choice `k` → file `fajr_file_first - 1 + k` |

`Z_fallback_1..4` land on 45–48. They are never referenced by number and must be copied last, because the DFPlayer glitch that they cover ends up playing the last file on the card.

The DFPlayer itself expects files numbered according to its own scheme (typically `0001.mp3`, `0002.mp3`, … in the order they are copied). See the README’s SD‑card section for user‑facing instructions.

---

### Display is optional (hot-plug watchdog)

`I2CSSD1306::setup()` probes the I2C address before allocating the frame buffer; no answer → `mark_failed()` and ESPHome carries on without it. `update_display` starts with `if (!id(oled).is_ready()) return;` so nothing draws into a buffer that does not exist (this was a null write and a boot loop in V5 when the display was absent). A 10 s `interval` sends a zero-length I2C write as an ACK probe: a failed display that answers gets `reset_to_construction_state()` + `call()` (full setup, buffer allocated once, poller re-registered under the same name); a display that was working, vanished and came back gets `setup()` again to resend the init sequence. Every `setup()` allocates a new 1 KB buffer and ESPHome never frees the old one, so setups are capped at 4 per boot; beyond that the log says to press Restart.

### Web page and Home Assistant entities

`web_server:` runs version 3 with `log: false` (set it to `true` to stream the log to the page) and five sorting groups. The OTA upload form on the page comes from ESPHome's stock page script; its `accept="application/octet-stream"` filter greys out `.bin` files in Safari on macOS, so use Chrome or `curl -F "update=@firmware.bin" http://athan.local/update`. The firmware is deliberately a single yaml file, so no custom page script is shipped. Every entity is a plain ESPHome template entity that reuses the scripts above:

- `button`: `web_stop` → `silence_audio`; `web_preview_fajr` → `web_preview` with the Fajr file; `web_refresh_times`; `web_check_update` / `web_install_update` (same state machine as the Update menu item, `update_check_state` 3 → 1/2 → 4); `web_restart`.
- `select`: `web_athan_select` (Athan 1–10), `web_htick_select` (None, Tick 1–10), `web_location_select` (the 15 keys). Their `set_action` writes the same globals the menu writes, then `publish_state`. They have no `lambda`; `sync_web_state` pushes device-side changes.
- `number`: `web_volume` (0–100, step 10) → `apply_volume`.
- `switch`: `web_athan_fajr/dhuhr/asr/maghrib/isha` use a `lambda` on the global (evaluated every loop, published on change) plus turn on/off actions, and **`restore_mode: DISABLED`**. That last line is load-bearing: with the default restore mode ESPHome calls `turn_off()` inside the switch `setup()` (priority 798), which runs the action before the display (priority 400) has a buffer. The first V6 build crashed on every boot for exactly this reason and also would have muted every prayer at each boot. The `Q` flag is deliberately not exposed as an entity; it stays device-only behind the 10-press guard.
- `binary_sensor`: `web_athan_playing`. `text_sensor`: `web_next_prayer`, `web_today_times`, `web_update_status` (carries the version), `web_ip` (`wifi_info`), `web_reset_reason` (`debug`). `sensor`: `web_free_heap` (`debug`).

**Memory budget (ESP8266, 80 KB RAM).** The linker's `RAM:` line at the end of a build is static usage; V6 sits around 40 KB and everything else (Wi‑Fi stack ~10 KB, entities, API connection, web clients, HTTP fetch buffers, 1 KB display buffer) comes out of the remainder as heap. Two things are easy to get wrong: (1) font glyph tables live in DRAM (`.rodata`), ~32 bytes per glyph, so every font lists its `glyphs:` explicitly instead of the ~100-glyph default; (2) string literals in lambdas are DRAM too, so long format strings use `PSTR()` with `snprintf_P`. Watch **Free Heap** on the web page after any change; a value that keeps dropping toward 8 KB precedes crash-reboot loops.

REST endpoints follow ESPHome's scheme, for example `POST /button/stop_audio/press`, `POST /select/location/set?option=woodland`, `POST /number/volume/set?value=40`; see README section 1.6.

### Development and testing

Suggested loop when changing the YAML:

1. Install ESPHome and create a `secrets.yaml` with `wifi_ssid` and `wifi_password` that match your local network.
2. Run:

   ```bash
   esphome run athan.yaml
   ```

   This builds and flashes over USB (or OTA once configured).
3. Keep the ESPHome logs open to watch `ESP_LOGI` output from the various components.

If you break parsing or networking code, most errors will show up in the logs (`prayer`, `tz`, `update` tags etc.).

---

### Extending or porting

Some ideas if you want to go further:

- Port to **ESP32** or newer boards and enable HTTPS for JSON endpoints.
- Use a larger screen (TFT) by replacing the `display:` component and rewriting `update_display`.
- Add more menu items or sensors in ESPHome (for example, brightness sensors to auto‑dim the display).
- Replace the JSON host with a small server that generates JSON on the fly from an existing timetable system.

If you do build something on top of this, I would be happy to learn from it.


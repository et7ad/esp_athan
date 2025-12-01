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
- `athan_file_index` (int, persisted) – DFPlayer file number to play for Athan.
- `htick_file_index` (int, persisted) – DFPlayer file number to play at the top of each hour (0 = disabled).
- `selected_location_index` (int, persisted) – index into the location key array.
- `selected_location_tz` (string, persisted) – full IANA timezone string.
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

  `http://raw.githack.com/Mahm0ud-end/athan_json/master/<location>/<year>/<DDD>.json`

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

- Sets `athan_playing = true`.
- Plays `id(athan_file_index)` on the DFPlayer.
- Turns the built‑in LED on for 5 minutes, then off, and marks `athan_playing = false` again.

#### Per‑second tick (`interval: 1s`)

- Ensures the persisted timezone is applied once when SNTP time becomes valid.
- Skips work until prayer times are successfully loaded.
- Checks whether the current time has passed `next_prayer_hour` / `next_prayer_minute` (with some care around Isha and rollover).
- When that condition is met, triggers `make_athan`, logs, recomputes the next prayer, and updates the display.

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
  - Next: advances `ui_menu_index` (0–6) and updates the OLED.
  - Select: dispatches based on the current index to enter the relevant submenu or perform actions such as starting an update check.

- **Submenus** use `ui_mode` values 2–5 and small helper indices (`athan_index`, `htick_index`, `location_index`) that do not touch persisted values until the user presses Select.

This design tries to keep actual writes to persisted globals limited to clear confirmation points so accidental button presses are less likely to store half‑finished state.

---

### JSON layout and adding locations

See the main README for the user‑facing explanation. From the firmware side:

- The location keys are kept in two identical `static const char* locs[15]` arrays in the `load_prayer_times` and `change_location_handler` lambdas.
- Both must be updated together when adding a new key.
- `selected_location_index` is the persisted index; `location_index` is used as a “preview” index while the location submenu is open.

Typical steps to add a new mosque:

1. Create `docs/timezones/<newkey>.json` with a `TZ` string.
2. Generate `/<newkey>/<year>/<DDD>.json` for every day of the year.
3. Add `<newkey>` to the `locs` arrays in `athan.yaml` at the desired index.
4. Rebuild and flash.

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

Key places where file numbers are used:

- `athan_file_index` – main Athan playback file.
- Athan preview submenu – uses `1 + athan_index` where `athan_index` is 0–9.
- Hourly tick submenu – uses `10 + htick_index` for indices `1–10` (0 means “none”).
- A few fixed indices like `22`, `23`, `25` for small tones.

The DFPlayer itself expects files numbered according to its own scheme (typically `0001.mp3`, `0002.mp3`, … in the order they are copied). See the README’s SD‑card section for user‑facing instructions.

---

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


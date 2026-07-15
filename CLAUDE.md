# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

ESPHome firmware + supporting data/scripts for an Islamic prayer clock built on an ESP8266 (`d1_mini`). The device calls the Athan at prayer time using a DFPlayer + SD card, shows status on an SSD1306 OLED, and fetches daily prayer times as small JSON files over plain HTTP. This is a hobby/hardware project — there is no test suite, no linter, no CI.

User-facing docs live in `README.md`; internals in `DEVELOPER.md`; the authoritative JSON contract in `prayertimes_specs.md`.

## Build / flash

The firmware is a single ESPHome YAML — no separate C++ sources. To build and flash:

```bash
# requires a sibling secrets.yaml with: wifi_ssid, wifi_password
esphome run firmware/athan.yaml
```

There is no `make`, no test runner, no formatter. ESPHome handles compile + upload (USB or OTA once configured).

## Architecture (the parts that span files)

**Almost all behavior is inline C++ lambdas inside `firmware/athan.yaml`** — globals, `script:` entries, `binary_sensor` `on_press` handlers, and the per-second `interval`. There is no C++ source tree to grep through. When tracing logic, search inside `athan.yaml` first.

**Two repos in one.** The yaml fetches data from `http://rawcdn.githack.com/et7ad/esp_athan/master/docs/...` — i.e. this same repo's `docs/` directory served via a raw.githack HTTP mirror (GitHub itself is HTTPS-only; the ESP8266 talks HTTP). Three URL patterns the firmware hits:
- `docs/timezones/<key>.json` — `{ "TZ": "..." }` (POSIX TZ string, not `Continent/City`)
- `docs/athantimes/<key>/<year>/<DDD>.json` — one file per Gregorian day, `DDD` is zero-padded day-of-year
- `docs/firmwareinfo/latest.json` — OTA version pointer

**Persisted globals are the contract with deployed devices.** Several globals in `athan.yaml` use `restore_value: true` (notably `selected_location_index`, `selected_location_tz`, `volume_level`, `athan_file_index`, `htick_file_index`). Anything indexed by these survives reflashing, so reordering must be avoided.

**Adding a mosque touches multiple places that must stay aligned:**
1. Both `static const char* locs[15]` arrays in `athan.yaml` (one in `load_prayer_times`, one in `change_location_handler`, plus the menu-preview block — currently 3 occurrences). They must match exactly.
2. `docs/timezones/<key>.json`
3. `docs/athantimes/<key>/<year>/` with one JSON per day, format per `prayertimes_specs.md` (16 keys, strict `HH:MM`, all strings).
4. README §4.4 location table.
5. **Never insert into or reorder existing slots** — `selected_location_index` is persisted, so a shift silently sends every deployed device to the wrong mosque. Only replace placeholder slots (`masjid7`…`masjid15`).

**Prayer JSON generation.** `scripts/break_json.py` splits a yearly source file into per-day `DDD.json` files following the spec; it backfills missing `*_iqa` fields via configurable offset and computes `doha` from `sunrise + 15min` when absent. `scripts/santaclara_prayer_times_parser.py` is a one-off PDF extractor for MCA timetables. Neither runs automatically.

**DFPlayer file numbering depends on copy order, not filename.** The DFPlayer module assigns file indices by the order files are written to the SD card. `SDCard_files/cpy_script.sh` (and `scripts/sd_card_cpy_script.sh`) copy in a deterministic order so that the numeric indices baked into the yaml (`athan_file_index`, `htick_file_index`, plus literals like `22`, `23`, `25` for click tones) resolve to the right MP3. Don't drag-and-drop — use the script.

**Display tweaks are localized.** The `display:` block (`platform: ssd1306_i2c`) is the only thing to touch for I2C address (`0x3C`/`0x3D`) or `flip_x` / `flip_y` orientation; no other code needs changing.

**Relay control from a laptop.** The yaml exposes a `web_server` so `scripts/relay_control.sh` (HTTP) or `scripts/relay_control_native.py` (ESPHome native API, needs `aioesphomeapi`) can toggle `external_relay` from a terminal — useful for testing without Home Assistant.

## Conventions worth knowing

- The project uses **POSIX TZ strings** (e.g. `PST8PDT,M3.2.0,M11.1.0`), not IANA `Continent/City`. The ESPHome `sntp` component does not handle the IANA form reliably here.
- Daily JSONs use 24-hour `HH:MM` with leading zeros; the firmware tolerates whitespace but the spec is strict — see `prayertimes_specs.md`. Times that look like AM but are actually PM (e.g. dhuhar `< 9`) are corrected by `load_prayer_times` with hardcoded `+12` adjustments. If you change the JSON producer, keep this in mind.
- `current_version` (top of `athan.yaml` `substitutions:`) and `docs/firmwareinfo/latest.json` together drive the in-device "check for update" flow.
- Built binaries are not committed (`firmware/binaries/` is gitignored); ESPHome rebuilds from the yaml.

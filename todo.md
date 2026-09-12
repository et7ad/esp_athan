# ESP Athan TODO

## Next Versionxw

### DFPlayer stuck recovery via hardware power cycling

- **Hardware change**: Wire DFPlayer VCC through an N-channel MOSFET (or NPN transistor) controlled by a free ESP GPIO pin, so the ESP can cut and restore power to the DFPlayer programmatically
- **Firmware change**: Add a watchdog that monitors playback duration — track when the last play command was sent and what the expected duration is (short UI click vs long athan). If the DFPlayer has been "playing" far longer than expected (e.g. a 1-second click still active after 10 seconds, or an athan still active after 6 minutes), trigger a power cycle: cut VCC via the MOSFET, wait ~500ms, restore VCC, wait ~3s for the clone to reinitialize, then restore volume and clear the athan_playing flag
- **Why**: Cheap MH2024K DFPlayer clones can lock up with the DAC/amplifier stuck on (LED stays on, no audio). The serial reset command (0x0C) does NOT recover a locked clone — only a full power cycle guarantees recovery

## Fallback only: single settings block in flash (do NOT do this unless the preference store runs out)

The ESP8266 flash preference store is 128 words. Each persisted object costs its size rounded up to
4-byte words plus one checksum word, so a lone bool or int costs 2 words whatever its type; only arrays
and strings get cheaper with smaller types. As of 2026-09-12 the firmware uses 85 words (globals 48,
relay switch 2, Wi-Fi credentials 26, API key 9). The store is positional (slot = setup order), so any
added/removed/resized persisted object moves the slots after it and resets them once (Wi-Fi and mosque
included). Never add a persisted global casually.

If more settings are ever needed and the words run out, switch to ONE persisted global
`settings` of type `uint8_t[128]` (33 words for everything the app owns, ~70 words total with relay,
Wi-Fi and API) and keep every existing global as it is but with `restore_value: false`:

- byte 0: layout version (lets a later change migrate instead of discarding)
- byte 1: flags: locked, 12h clock, Q, Fajr/Dhuhr/Asr/Maghrib/Isha on/off
- bytes 2-9: volume, Fajr volume, athan choice, Fajr athan choice, tick choice, window start, window end, location index
- bytes 10-13: cached schedule day and year
- bytes 14-27: seven prayer times as 16-bit minutes-of-day
- bytes 28-75: timezone string (POSIX strings are 22-35 chars)
- bytes 76-127: spare (future settings go here, no slot ever moves again)

Implementation: one `unpack` lambda in `on_boot` (block -> globals) and one `pack` step in the 1 s
`sync_web_state` interval (globals -> block, copied only if a byte differs; ESPHome then writes the
flash). No other code in the file changes.

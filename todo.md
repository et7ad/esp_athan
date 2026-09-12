# ESP Athan TODO

## Next Versionxw

### DFPlayer: hardware changes for the next PCB

**IMPORTANT, do first: wire the DFPlayer BUSY pin to a spare ESP GPIO.**
- BUSY is low while the module plays and high when idle. Today the firmware only knows what it *asked* the module to do; with BUSY it knows what the module is *doing*. That turns every guess into a check: "asked to play but BUSY says idle" (stuck / ignored command → resend or power-cycle), "playing when nothing was requested" (runaway → stop), and it is what a proper playback watchdog needs.
- GPIO choice: GPIO0 is the practical candidate (BUSY idles high, which is the normal-boot level for GPIO0; it is also the programming pin, so it must be easy to isolate on the header). GPIO15 cannot be used (BUSY high at boot would select the wrong boot mode). GPIO2 drives the LED, GPIO16 the OLED reset.

**Optional: DFPlayer power through an N-channel MOSFET (or NPN) on a spare GPIO.**
- Lets the firmware do the only thing that reliably recovers a locked clone (LED stuck on, no audio; the serial reset 0x0C does not): cut VCC, wait ~500 ms, restore, wait ~3 s, restore the volume.
- Bonus: keep the module unpowered for the first ~3 s after the ESP boots so it never sees the ESP8266 boot-ROM log on GPIO1 (its RX line), the classic cause of clones playing on their own after a reset. The firmware already sends stops after boot as a workaround.
- Firmware side once it exists: a watchdog on expected playback duration (short click vs athan) that power-cycles the module when it is "playing" far longer than it should, or, with BUSY wired, whenever BUSY contradicts the request.

**Optional: DFPlayer RX on GPIO15 instead of GPIO1.**
- ESP8266 UART0 can be swapped to TX=GPIO15 / RX=GPIO13 in `uart:`; the boot ROM only prints on GPIO1, so the module would never hear it. GPIO13 is the relay today and would have to move.

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

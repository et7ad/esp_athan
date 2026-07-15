# masjid15 — Visalia, California

This slot's prayer-time data (`docs/athantimes/masjid15/<year>/DDD.json`) is for
**Visalia, California, USA** (Pacific time — see `docs/timezones/masjid15.json`).

`masjid15` is firmware **slot 15**. It was one of the reserved placeholder slots;
the **key is intentionally left as `masjid15`** so the persisted
`selected_location_index` on already-deployed devices keeps pointing at the same
slot. Only the *data* behind the key changed — not its position.

## Where the data comes from

Times are generated from **[IslamicFinder](https://www.islamicfinder.org/)**'s
yearly prayer-times page for Visalia, CA.

1. **Capture the HTML.** IslamicFinder renders the whole year as one HTML page.
   The exact steps to grab that HTML from the browser are shown in the annotated
   screenshot:

   `scripts/helping/parse_islamicfinder_yearly_get_html.jpg`

   Save the captured page as e.g. `Visalia<YYYY>.html` into
   `scripts/helping/preparing/`.

2. **Parse it into per-day JSON.** Run the parser:

   ```bash
   python3 scripts/helping/parse_islamicfinder_yearly.py
   # or point it at a specific file:
   python3 scripts/helping/parse_islamicfinder_yearly.py path/to/Visalia2026.html
   ```

   It writes `001.json … 365.json` (spec: `prayertimes_specs.md`) into a folder
   named after the year, right next to the HTML. Copy that folder here as
   `docs/athantimes/masjid15/<year>/`.

## Important caveat about iqama times

The IslamicFinder source provides **only adhan (call-to-prayer) times plus
sunrise** — it has **no iqama times and no doha**. The parser therefore
**derives** those fields:

- `doha`        = `sunrise` + 15 min
- `fajr_iqa`    = `fajr`    + 30 min
- `dhuhar_iqa`  = `dhuhar`  + 10 min
- `asr_iqa`     = `asr`     + 10 min
- `maghrib_iqa` = `maghrib` + 10 min
- `isha_iqa`    = `isha`    + 20 min

So the `*_iqa` values here are **estimates, not a specific mosque's official
congregation times**. Adjust the offsets at the top of the parser if a real
local schedule is available.

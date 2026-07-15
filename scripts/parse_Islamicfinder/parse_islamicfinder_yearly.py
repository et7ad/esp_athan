#!/usr/bin/env python3
"""Parse an IslamicFinder *yearly* HTML export into per-day prayer JSON files.

IslamicFinder's yearly page renders one ``.month-block`` per Gregorian month.
Each block holds a ``.prayer-table`` whose header row is::

    Day | Fajr | Sunrise | Dhuhr | Asr | Maghrib | Isha

and one ``.prayer-row`` per day, with times in 12-hour ``HH:MM AM/PM`` form.

That source carries **only adhan times** — it has no iqama times and no doha.
Everything the output spec (``prayertimes_specs.md``) needs but the source lacks
is derived here:

    * doha        = sunrise + DOHA_OFFSET_FROM_SUNRISE (15 min, matching the
                    rest of this repo — see santaclara_prayer_times_parser.py
                    and break_json.py).
    * *_iqa       = adhan + backup_iqamah_offset[prayer].

12-hour source times are converted to strict 24-hour ``HH:MM`` (the AM/PM marker
makes this unambiguous, so — unlike break_json.py — no "looks like AM but is
really PM" heuristics are needed here).

Usage
-----
    # process one file explicitly
    python3 parse_islamicfinder_yearly.py path/to/Visalia2026.html

    # or, with no argument, process every *.html under ./preparing/
    python3 parse_islamicfinder_yearly.py

For each input HTML, the year is read from the month headers (e.g.
"January 2026" -> 2026) and a folder named after that year is created **right
next to the HTML file**, e.g.::

    scripts/helping/preparing/Visalia2026.html
    scripts/helping/preparing/2026/001.json ... 365.json

The 001.json .. 366.json files follow prayertimes_specs.md (16 keys, all
strings, strict HH:MM, DDD = zero-padded day-of-year).
"""

import calendar
import json
import pathlib
import sys
from datetime import datetime

try:
    from bs4 import BeautifulSoup
except ImportError:
    sys.exit(
        "This script needs BeautifulSoup. Install it with:\n"
        "    pip install beautifulsoup4"
    )

# ---- CONFIG ----------------------------------------------------------------
# Directory scanned for *.html when no path is given on the command line.
DEFAULT_INPUT_DIR = pathlib.Path(__file__).resolve().parent / "preparing"

# Fallback iqamah offsets (minutes after the adhan). The IslamicFinder source
# has NO iqama times, so every one of these is applied to every day. Same
# defaults as break_json.py. Edit freely.
backup_iqamah_offset = {
    "fajr":    30,
    "dhuhar":  10,
    "asr":     10,
    "maghrib": 10,
    "isha":    20,
}

# Doha = sunrise + this many minutes (the source has no doha column).
DOHA_OFFSET_FROM_SUNRISE = 15
# ----------------------------------------------------------------------------

# Header cells the source is expected to expose, in order. Used both to
# validate each month's header and to map columns -> prayer fields.
EXPECTED_HEADER = ["Day", "Fajr", "Sunrise", "Dhuhr", "Asr", "Maghrib", "Isha"]

# Final output key order — the 16 keys required by prayertimes_specs.md.
OUTPUT_KEY_ORDER = [
    "year", "month", "#", "day",
    "fajr", "fajr_iqa",
    "sunrise", "doha",
    "dhuhar", "dhuhar_iqa",
    "asr", "asr_iqa",
    "maghrib", "maghrib_iqa",
    "isha", "isha_iqa",
]

MONTH_NAME_TO_NUMBER = {name: i for i, name in enumerate(calendar.month_name) if name}


def big_error(msg):
    """Print a loud banner and stop — mirrors break_json.py's failure mode."""
    bar = "!" * 80
    print("\n" + bar)
    print("!!!!!  FATAL ERROR — STOPPING  !!!!!".center(80))
    print(bar)
    print(msg)
    print(bar + "\n")
    sys.exit(1)


def to_24h(time_str, context):
    """Convert a 12-hour 'HH:MM AM/PM' string to strict 24-hour 'HH:MM'."""
    s = " ".join(str(time_str).split())  # collapse internal/edge whitespace
    try:
        return datetime.strptime(s.upper(), "%I:%M %p").strftime("%H:%M")
    except ValueError:
        big_error(f"Could not parse time {time_str!r} ({context}).")


def add_minutes(hhmm, minutes):
    """Add minutes to a 24-hour 'HH:MM' string, wrapping at midnight."""
    h, m = hhmm.split(":")
    total = (int(h) * 60 + int(m) + minutes) % (24 * 60)
    return f"{total // 60:02d}:{total % 60:02d}"


def parse_month_block(block, html_path):
    """Return (year, month_number, [row_dicts]) for one .month-block.

    Each row_dict has raw source fields (day + 6 adhan times, still 12-hour).
    """
    name_el = block.select_one(".monthNameeng")
    if name_el is None:
        big_error(f"A month block in {html_path} has no .monthNameeng header.")
    header_text = name_el.get_text(strip=True)  # e.g. "January 2026"

    parts = header_text.split()
    if len(parts) != 2 or parts[0] not in MONTH_NAME_TO_NUMBER or not parts[1].isdigit():
        big_error(f"Unexpected month header {header_text!r} in {html_path}.")
    month_number = MONTH_NAME_TO_NUMBER[parts[0]]
    year = int(parts[1])

    rows = block.select(".prayer-row")
    if not rows:
        big_error(f"Month block {header_text!r} in {html_path} has no rows.")

    # First .prayer-row is the header (class 'prayer-row prayer-header').
    header_cells = [d.get_text(strip=True) for d in rows[0].find_all("div")]
    if header_cells != EXPECTED_HEADER:
        big_error(
            f"Header mismatch in {header_text!r} ({html_path}).\n"
            f"  expected: {EXPECTED_HEADER}\n"
            f"  found:    {header_cells}"
        )

    out_rows = []
    for row in rows[1:]:
        cells = [d.get_text(strip=True) for d in row.find_all("div")]
        if len(cells) != len(EXPECTED_HEADER):
            big_error(
                f"{header_text} in {html_path}: expected "
                f"{len(EXPECTED_HEADER)} cells, got {len(cells)}: {cells}"
            )
        out_rows.append({
            "day": cells[0],
            "fajr": cells[1],
            "sunrise": cells[2],
            "dhuhar": cells[3],
            "asr": cells[4],
            "maghrib": cells[5],
            "isha": cells[6],
        })

    return year, month_number, out_rows


def build_day_object(year, month_number, raw):
    """Turn one raw source row into the final 16-key output object."""
    day = int(raw["day"])
    date = datetime(year, month_number, day)
    ctx = f"{year}-{month_number:02d}-{day:02d}"

    fajr = to_24h(raw["fajr"], f"fajr {ctx}")
    sunrise = to_24h(raw["sunrise"], f"sunrise {ctx}")
    dhuhar = to_24h(raw["dhuhar"], f"dhuhar {ctx}")
    asr = to_24h(raw["asr"], f"asr {ctx}")
    maghrib = to_24h(raw["maghrib"], f"maghrib {ctx}")
    isha = to_24h(raw["isha"], f"isha {ctx}")

    obj = {
        "year": str(year),
        "month": str(month_number),
        "#": calendar.day_name[date.weekday()],
        "day": str(day),
        "fajr": fajr,
        "fajr_iqa": add_minutes(fajr, backup_iqamah_offset["fajr"]),
        "sunrise": sunrise,
        "doha": add_minutes(sunrise, DOHA_OFFSET_FROM_SUNRISE),
        "dhuhar": dhuhar,
        "dhuhar_iqa": add_minutes(dhuhar, backup_iqamah_offset["dhuhar"]),
        "asr": asr,
        "asr_iqa": add_minutes(asr, backup_iqamah_offset["asr"]),
        "maghrib": maghrib,
        "maghrib_iqa": add_minutes(maghrib, backup_iqamah_offset["maghrib"]),
        "isha": isha,
        "isha_iqa": add_minutes(isha, backup_iqamah_offset["isha"]),
    }
    # Emit exactly the 16 keys, in spec order.
    return date, {k: obj[k] for k in OUTPUT_KEY_ORDER}


def process_html(html_path):
    """Parse one IslamicFinder yearly HTML file and write per-day JSON files."""
    print(f"Processing {html_path}")
    soup = BeautifulSoup(html_path.read_text(encoding="utf-8"), "html.parser")

    blocks = soup.select(".month-block")
    if len(blocks) != 12:
        big_error(f"Expected 12 month blocks in {html_path}, found {len(blocks)}.")

    # Parse all months first so we can validate the whole year before writing.
    file_year = None
    days = []  # (date, obj)
    for index, block in enumerate(blocks, start=1):
        year, month_number, raw_rows = parse_month_block(block, html_path)

        if month_number != index:
            big_error(
                f"Month order mismatch in {html_path}: block #{index} is "
                f"month {month_number}."
            )
        if file_year is None:
            file_year = year
        elif year != file_year:
            big_error(
                f"Mixed years in {html_path}: saw {file_year} and {year}. "
                f"This script expects one calendar year per file."
            )

        expected_days = calendar.monthrange(year, month_number)[1]
        if len(raw_rows) != expected_days:
            big_error(
                f"{calendar.month_name[month_number]} {year} in {html_path}: "
                f"expected {expected_days} days, found {len(raw_rows)}."
            )

        for raw in raw_rows:
            days.append(build_day_object(year, month_number, raw))

    expected_year_days = 366 if calendar.isleap(file_year) else 365
    if len(days) != expected_year_days:
        big_error(
            f"{html_path}: expected {expected_year_days} days for {file_year}, "
            f"built {len(days)}."
        )

    # Output folder = year name, right next to the HTML file.
    output_dir = html_path.parent / str(file_year)
    output_dir.mkdir(exist_ok=True)

    for date, obj in days:
        day_of_year = date.timetuple().tm_yday
        out_path = output_dir / f"{day_of_year:03d}.json"
        with open(out_path, "w", encoding="utf-8") as f:
            json.dump(obj, f, indent=2)

    print(f"✓ Wrote {len(days)} files to {output_dir}")


def main(argv):
    if len(argv) > 1:
        inputs = [pathlib.Path(p) for p in argv[1:]]
        for p in inputs:
            if not p.is_file():
                big_error(f"Input file not found: {p}")
    else:
        inputs = sorted(DEFAULT_INPUT_DIR.glob("*.html"))
        if not inputs:
            big_error(
                f"No *.html files found in {DEFAULT_INPUT_DIR}.\n"
                f"Pass an HTML path explicitly, e.g.:\n"
                f"    python3 {pathlib.Path(argv[0]).name} path/to/City2026.html"
            )

    for html_path in inputs:
        process_html(html_path.resolve())


if __name__ == "__main__":
    main(sys.argv)

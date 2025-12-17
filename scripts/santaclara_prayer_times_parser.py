#!/usr/bin/env python3
import json
import pathlib
import calendar
from datetime import datetime, timedelta
import pdfplumber


MONTH_NAMES = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
]


# Base directory where output folders (e.g. "2025_MCA_Prayer_Time")
# will be created. By default this is the current directory containing
# the script, but it can be changed to any absolute or relative path.
OUTPUT_BASE_DIR = pathlib.Path(".")


def extract_tables_from_pdf(pdf_path):
    """Extract 12 monthly tables from a PDF and convert to validated dicts.

    - Each table's first row contains a header whose first cell is the month name.
    - Output objects contain:
        {"month": <month_name>, "rows": <data_rows>}
    - The first two data rows (after the header row) are discarded, as they
      correspond to header information that will be defined manually later.
    - Asserts:
        * Exactly 12 tables are found in the file.
        * The i-th table corresponds to the i-th calendar month.
    """

    monthly_tables = []

    with pdfplumber.open(pdf_path) as pdf:
        month_index = 0

        for page in pdf.pages:
            tables = page.extract_tables() or []
            for table in tables:
                # Skip completely empty tables, if any
                if not table or not table[0]:
                    continue

                month_index += 1

                if month_index > 12:
                    raise AssertionError(
                        f"Expected exactly 12 tables, found more than 12 in {pdf_path}"
                    )

                header_row = table[0]
                month_cell = header_row[0]

                if month_cell is None or str(month_cell).strip() == "":
                    raise AssertionError(
                        f"Missing month name in table {month_index} of {pdf_path}"
                    )

                month_name = str(month_cell).strip()
                expected_month = MONTH_NAMES[month_index - 1]

                if month_name.lower() != expected_month.lower():
                    raise AssertionError(
                        "Month/table order mismatch: "
                        f"table {month_index} has '{month_name}', "
                        f"expected '{expected_month}' in {pdf_path}"
                    )

                # Data rows are everything after the first header row. The
                # first two of those rows are themselves header rows that
                # will be defined manually, so skip them.
                data_rows = table[1:] if len(table) > 1 else []
                if len(data_rows) > 2:
                    data_rows = data_rows[2:]
                else:
                    data_rows = []

                table_data = {
                    "month": month_name,
                    "month_number": month_index,
                    "rows": data_rows,
                }
                monthly_tables.append(table_data)

    if month_index != 12:
        raise AssertionError(
            f"Expected exactly 12 tables in {pdf_path}, found {month_index}"
        )

    return monthly_tables

# the source data:
# every row has following format   
# "1", day of month
# "6:05", fajr athan
# "6:30", fajr iqama
# "7:22", sunrise (doha doesnt exist make it 15 mins after sunrise)
# "12:15", dhuhr athan
# "12:35", dhuhr iqama
# "2:44", asr athan
# "3:15", asr iqama
# "5:04", maghrib athan
# "6:19", isha athan
# "8:00", isha iqama

# target format: the field "#" is not needed because doesnt exist in the source.
# {
#   "year": "2025", # year defined in this file at beginning
#   "month": "1", # month number is defined in the dictionary when the function extract_tables_from_pdf is used
#   "#": "Wednesday", # doesnt exist in source, compute it based on the calender imported and the date
#   "day": "1", # first entry in the row
#   "fajr": "06:06", # fajr athan
#   "fajr_iqa": "06:36", # fajr iqama
#   "sunrise": "07:24", # sunrise
#   "doha": "07:39", # doha time (not in source, can be calculated as 15 mins after sunrise)
#   "dhuhar": "12:14", # dhuhr athan
#   "dhuhar_iqa": "12:34", # dhuhr iqama
#   "asr": "02:39", # asr athan
#   "asr_iqa": "02:59", # asr iqama
#   "maghrib": "04:57", # maghrib athan
#   "maghrib_iqa": "05:09", # doesnt exist in source and not needed, so calculate it 5 minutes after maghrib athan
#   "isha": "06:16", # isha athan
#   "isha_iqa": "07:10" # isha iqama
# }


def _normalize_time(time_str):
    """Normalize a time string to HH:MM (24-hour) if possible.

    Returns the original string if it can't be safely parsed as H:MM/HH:MM.
    """

    if not time_str:
        return time_str

    s = str(time_str).strip()
    parts = s.split(":")
    if len(parts) != 2:
        return s

    h, m = parts[0].strip(), parts[1].strip()
    if not (h.isdigit() and m.isdigit()):
        return s

    hours = int(h)
    minutes = int(m)
    if not (0 <= hours < 24 and 0 <= minutes < 60):
        return s

    return f"{hours:02d}:{minutes:02d}"


def _add_minutes_to_time(time_str, minutes):
    """Return time_str offset by given minutes, formatted as HH:MM.

    If parsing fails or time_str is empty, returns the original time_str.
    """

    if not time_str:
        return time_str

    try:
        base_str = _normalize_time(time_str)
        base = datetime.strptime(base_str, "%H:%M")
        new_time = base + timedelta(minutes=minutes)
        return new_time.strftime("%H:%M")
    except Exception:
        return time_str


def process_prayer_times():
    """Process prayer times and create individual JSON files for each day.

    - Scans for all PDF files in the current directory.
    - For each PDF, derives the year and an output folder name.
    - Creates a subfolder under OUTPUT_BASE_DIR using the PDF stem
        (e.g. "2025_MCA_Prayer_Time").
    - Writes one JSON file per calendar day with normalized prayer times.
    """
    # Process each PDF file directly (no intermediate *_tables.json files)
    for pdf_file in OUTPUT_BASE_DIR.glob("*.pdf"):
        # Derive year from first 4 characters of filename (e.g. "2025_MCA_...")
        year_str = pdf_file.stem[:4]
        if not year_str.isdigit():
            print(f"Skipping {pdf_file}: cannot determine year from filename")
            continue
        year = int(year_str)

        # Create folder based on original PDF name (without extension)
        folder_name = pdf_file.stem
        output_dir = OUTPUT_BASE_DIR / folder_name
        output_dir.mkdir(exist_ok=True)

        print(f"Processing {pdf_file} -> {output_dir}")

        try:
            tables = extract_tables_from_pdf(pdf_file)
        except Exception as e:
            print(f"Error extracting tables from {pdf_file}: {e}")
            continue

        # Each table corresponds to one month
        for table in tables:
            month_number = table.get("month_number")
            rows = table.get("rows", [])

            if not month_number:
                print(f"Skipping table without month_number in {pdf_file}")
                continue

            # Find the rows with actual prayer times
            prayer_data_rows = []
            for row in rows:
                if (
                    row
                    and len(row) >= 11
                    and row[0] is not None
                    and str(row[0]).strip().isdigit()
                ):
                    prayer_data_rows.append(row)

            # Process each day in this month
            for row in prayer_data_rows:
                try:
                    day_num = int(str(row[0]).strip())

                    date = datetime(year, month_number, day_num)
                    weekday_name = calendar.day_name[date.weekday()]

                    # Compute derived times based on comments in this file
                    doha_time = _add_minutes_to_time(row[3], 15)  # 15 mins after sunrise
                    maghrib_iqa_time = _add_minutes_to_time(row[8], 5)  # 5 mins after maghrib athan

                    # Create prayer times object (mapping follows documented format)
                    prayer_data = {
                        "year": str(year),
                        "month": str(month_number),
                        "#": weekday_name,
                        "day": str(day_num),
                        "fajr": _normalize_time(row[1]),
                        "fajr_iqa": _normalize_time(row[2]),
                        "sunrise": _normalize_time(row[3]),
                        "doha": doha_time,
                        "dhuhar": _normalize_time(row[4]),
                        "dhuhar_iqa": _normalize_time(row[5]),
                        "asr": _normalize_time(row[6]),
                        "asr_iqa": _normalize_time(row[7]),
                        "maghrib": _normalize_time(row[8]),
                        "maghrib_iqa": maghrib_iqa_time,
                        "isha": _normalize_time(row[9]),
                        "isha_iqa": _normalize_time(row[10]) if len(row) > 10 else "",
                    }

                    # Create day filename (day of year), zero-padded to 3 digits
                    day_of_year = date.timetuple().tm_yday
                    filename = f"{day_of_year:03d}.json"

                    # Save to output directory
                    output_path = output_dir / filename
                    with open(output_path, 'w') as f:
                        json.dump(prayer_data, f, indent=2)

                    # print(
                    #     f"Created {filename} for {date.strftime('%Y-%m-%d')} ({weekday_name})"
                    # )

                except (ValueError, IndexError) as e:
                    print(f"Skipping row in {pdf_file}: {e}")
                    continue

        print(f"✓ Completed {folder_name}")

if __name__ == "__main__":
    process_prayer_times()
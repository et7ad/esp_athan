import json
import os
import sys

# ---- CONFIG ----
INPUT_FILE = "./2026.json"        # your big file
OUTPUT_DIR = "./output_jsons"     # output folder

# Fallback iqamah offsets (minutes after the prayer time) used ONLY when the
# corresponding iqa value is missing from the input. Edit freely.
backup_iqamah_offset = {
    "fajr":    30,
    "dhuhar":  10,
    "asr":     10,
    "maghrib": 10,
    "isha":    20,
}

# Doha = sunrise + this many minutes, when doha is missing from the input.
DOHA_OFFSET_FROM_SUNRISE = 15
# ----------------

REQUIRED_DATE_KEYS = ["year", "month", "#", "day"]
REQUIRED_PRAYER_KEYS = ["fajr", "sunrise", "dhuhar", "asr", "maghrib", "isha"]
IQA_PRAYERS = ["fajr", "dhuhar", "asr", "maghrib", "isha"]

# Final output key order — must match Example_output.json (16 keys).
OUTPUT_KEY_ORDER = [
    "year", "month", "#", "day",
    "fajr", "fajr_iqa",
    "sunrise", "doha",
    "dhuhar", "dhuhar_iqa",
    "asr", "asr_iqa",
    "maghrib", "maghrib_iqa",
    "isha", "isha_iqa",
]


def big_error(msg):
    bar = "!" * 80
    print("\n" + bar)
    print("!!!!!  FATAL ERROR — STOPPING  !!!!!".center(80))
    print(bar)
    print(msg)
    print(bar + "\n")
    sys.exit(1)


def add_minutes(time_str, minutes):
    """Add minutes to an HH:MM 12-hour time string (wraps 12:xx -> 01:xx)."""
    parts = time_str.strip().split(":")
    if len(parts) != 2:
        raise ValueError(f"Invalid time format: {time_str!r}")
    h = int(parts[0])
    m = int(parts[1])
    total = (h * 60 + m + minutes) % (12 * 60)
    new_h = total // 60
    new_m = total % 60
    if new_h == 0:
        new_h = 12
    return f"{new_h:02d}:{new_m:02d}"


with open(INPUT_FILE, "r", encoding="utf-8") as f:
    data = json.load(f)

headers = data[0]
rows = data[1:]

# Convert headers (lowercase, remove spaces, map Iqa. -> <prev>_iqa)
clean_headers = []
last_prayer = None
for h in headers:
    h_clean = h.strip().lower()
    if h_clean == "iqa.":
        clean_headers.append((last_prayer + "_iqa") if last_prayer else "iqa")
    else:
        clean_headers.append(h_clean)
        last_prayer = h_clean

os.makedirs(OUTPUT_DIR, exist_ok=True)

for i, row in enumerate(rows, start=1):
    obj = {}
    for key, val in zip(clean_headers, row):
        if isinstance(val, str):
            val = val.strip()
        obj[key] = val

    # Best-effort label for error messages
    label = f"row {i}"
    if all(obj.get(k) not in (None, "") for k in REQUIRED_DATE_KEYS):
        label = f"{obj['year']}-{obj['month']}-{obj['day']} ({obj['#']}) [row {i}]"

    # --- Validate date fields ---
    missing_date = [k for k in REQUIRED_DATE_KEYS if obj.get(k) in (None, "")]
    if missing_date:
        big_error(
            f"Missing required date field(s) {missing_date} in {label}.\n"
            f"All of year, month, #, day are mandatory."
        )

    # --- Validate prayer times (sunrise included) ---
    missing_prayer = [k for k in REQUIRED_PRAYER_KEYS if obj.get(k) in (None, "")]
    if missing_prayer:
        big_error(
            f"Missing required prayer time(s) {missing_prayer} in {label}.\n"
            f"All of {REQUIRED_PRAYER_KEYS} are mandatory."
        )

    # --- Doha fallback: sunrise + 15 min ---
    if not obj.get("doha"):
        obj["doha"] = add_minutes(obj["sunrise"], DOHA_OFFSET_FROM_SUNRISE)

    # --- Iqamah fallbacks ---
    for prayer in IQA_PRAYERS:
        iqa_key = prayer + "_iqa"
        if not obj.get(iqa_key):
            offset = backup_iqamah_offset.get(prayer)
            if offset is None:
                big_error(f"No backup_iqamah_offset entry for {prayer!r}.")
            obj[iqa_key] = add_minutes(obj[prayer], offset)

    # Build final ordered object with exactly the 16 keys
    out_obj = {k: obj[k] for k in OUTPUT_KEY_ORDER}

    filename = f"{i:03d}.json"
    path = os.path.join(OUTPUT_DIR, filename)
    with open(path, "w", encoding="utf-8") as out:
        json.dump(out_obj, out, indent=2)

print(f"Done! Generated {len(rows)} files in '{OUTPUT_DIR}'")

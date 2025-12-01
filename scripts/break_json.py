import json
import os

# ---- CONFIG ----
INPUT_FILE = "./2026.json"        # your big file
OUTPUT_DIR = "./output_jsons"     # output folder
# ----------------

with open(INPUT_FILE, "r", encoding="utf-8") as f:
    data = json.load(f)

headers = data[0]   # first row
rows = data[1:]     # remaining day rows

# Convert headers (lowercase, remove spaces, map Iqa.)
clean_headers = []
last_prayer = None

for h in headers:
    h_clean = h.strip().lower()

    if h_clean == "iqa.":
        # Map to "<previous_prayer>_iqa"
        if last_prayer:
            clean_headers.append(last_prayer + "_iqa")
        else:
            clean_headers.append("iqa")
    else:
        clean_headers.append(h_clean)
        last_prayer = h_clean

# Ensure output folder exists
os.makedirs(OUTPUT_DIR, exist_ok=True)

# Output each day as 001.json, 002.json, ...
for i, row in enumerate(rows, start=1):
    obj = {}

    # Build object {key: value}
    for key, val in zip(clean_headers, row):
        if isinstance(val, str):
            val = val.strip()  # trim spaces
        obj[key] = val

    # filename e.g. "001.json"
    filename = f"{i:03d}.json"
    path = os.path.join(OUTPUT_DIR, filename)

    with open(path, "w", encoding="utf-8") as out:
        json.dump(obj, out, indent=2)

print(f"Done! Generated {len(rows)} files in '{OUTPUT_DIR}'")

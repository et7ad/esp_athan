# Prayer Times JSON Specification

This document specifies the **output format** for daily prayer time JSON files. It is intended for anyone generating compatible data, regardless of their source or tools.

The focus here is **only on outputs**: directory layout, filenames, JSON structure, field meanings, and exact value formats.

---

## 1. Directory & Filenames

- On the HTTP server, all daily prayer JSON files live under a base path like `docs/athantimes/`.
- Under that base path, every masjid has a folder, and inside every masjid is a folder for each year. 
  - Example folders:
    - `docs/athantimes/davis/2025/`
    - `docs/athantimes/santaclara/2025/`
- Inside each `<year>/` folder, there is **one JSON file per Gregorian calendar day** for that year.
- File naming convention (per day):
  - File name: `DDD.json`
  - `DDD` is the **day-of-year** number, zero-padded to 3 digits:
    - `001.json`  day-of-year 1 (e.g., January 1)
    - `032.json`  day-of-year 32 (e.g., February 1 in a non-leap year)
    - `365.json` or `366.json`  last day of the year (depending on leap year)
- Each `DDD.json` file represents **exactly one calendar date** in the given `year`.

---

## 2. JSON File Structure

- Each daily file (`DDD.json`) contains **one JSON object** (not an array).
- All keys are **strings** and all values are **strings**.
- Full field list (all fields are required):

| Key           | Type   | Example   | Description |
|--------------|--------|-----------|-------------|
| `year`       | string | `"2025"` | Four-digit Gregorian year. Same for all files in that folder. |
| `month`      | string | `"1"`    | Gregorian month number, `1`–`12`, **not zero-padded** (January = `"1"`, October = `"10"`). |
| `#`          | string | `"Wednesday"` | Full English weekday name for that date: one of `"Monday"`, `"Tuesday"`, `"Wednesday"`, `"Thursday"`, `"Friday"`, `"Saturday"`, `"Sunday"`. |
| `day`        | string | `"1"`    | Day of month, `1`–`31`, **not zero-padded**. |
| `fajr`       | string | `"06:05"` | Fajr **adhan** time (call to prayer). |
| `fajr_iqa`   | string | `"06:30"` | Fajr **iqama** (congregational prayer) time. |
| `sunrise`    | string | `"07:22"` | Sunrise time. |
| `doha`       | string | `"07:37"` | Duha time. In this dataset, it is usually defined as **15 minutes after `sunrise`**. |
| `dhuhar`     | string | `"12:15"` | Dhuhr adhan time. |
| `dhuhar_iqa` | string | `"12:35"` | Dhuhr iqama time. |
| `asr`        | string | `"14:44"` | Asr adhan time (24-hour format). |
| `asr_iqa`    | string | `"15:15"` | Asr iqama time. |
| `maghrib`    | string | `"17:04"` | Maghrib adhan time. |
| `maghrib_iqa`| string | `"17:09"` | Maghrib iqama time. In this dataset, it is defined as **5 minutes after `maghrib`**. |
| `isha`       | string | `"18:19"` | Isha adhan time. |
| `isha_iqa`   | string | `"20:00"` | Isha iqama time. |

> Note: While empty strings are technically possible in JSON, a **valid, complete dataset** is expected to provide a correctly formatted time for every time field above.

---

## 3. Time Format Requirements

All time fields (`fajr`, `fajr_iqa`, `sunrise`, `doha`, `dhuhar`, `dhuhar_iqa`, `asr`, `asr_iqa`, `maghrib`, `maghrib_iqa`, `isha`, `isha_iqa`) **must** follow these rules:

- **Format:** `HH:MM` (24-hour clock), where:
  - `HH` is **exactly two digits**: `00`–`23`.
  - `MM` is **exactly two digits**: `00`–`59`.
- Examples of **valid** times:
  - `"00:00"`, `"05:09"`, `"06:30"`, `"12:05"`, `"23:59"`.
- Examples of **invalid / not tolerated** times:
  - `"6:5"` (missing leading zeros — should be `"06:05"`).
  - `"6:05"` (one-digit hour — should be `"06:05"`).
  - `"06:5"` (one-digit minutes — should be `"06:05"`).
  - `"#:##"`, `"##:#"`, `"25:00"`, `"12:60"` (invalid pattern or range).
- Regular expression for validation:

  ```regex
  ^([01][0-9]|2[0-3]):[0-5][0-9]$
  ```

Any producer of this format **must normalize times** into the strict `HH:MM` form before writing JSON.


---

## 4. Example: A Complete Daily File

Below is a **realistic example** of a single daily file that follows this specification.

**File path:** `docs/athantimes/some_masjid/2025/001.json`

```json
{
  "year": "2025",
  "month": "1",
  "#": "Wednesday",
  "day": "1",
  "fajr": "06:05",
  "fajr_iqa": "06:30",
  "sunrise": "07:22",
  "doha": "07:37",
  "dhuhar": "12:15",
  "dhuhar_iqa": "12:35",
  "asr": "02:44",
  "asr_iqa": "03:15",
  "maghrib": "05:04",
  "maghrib_iqa": "05:09",
  "isha": "06:19",
  "isha_iqa": "08:00"
}
```

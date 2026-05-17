#!/usr/bin/env python3
"""
Generate interactive Plotly HTML plots of prayer times.

Layout assumed (matches docs/athantimes/ in this repo):

    <base>/<masjid>/<year>/DDD.json     e.g. davis/2025/001.json

For every <masjid>/<year>/ that exists, this writes:

    <base>/<masjid>/prayers_plots_<year>.html

Iqama times are ignored; only the 7 adhan/event times are plotted:
    fajr, sunrise, doha, dhuhar, asr, maghrib, isha

Stored JSON times do not carry AM/PM markers, so this script applies
the same AM/PM correction the firmware (firmware/athan.yaml) does:
    * dhuhar:              if hour <  9 -> hour += 12
    * asr / maghrib / isha: if hour < 12 -> hour += 12
    * fajr / sunrise / doha: no adjustment (always AM)

Usage:
    python plot_prayer_times.py <prayertimes_base_dir>

Example:
    python scripts/plot_prayer_times.py docs/athantimes
"""

from __future__ import annotations

import argparse
import datetime as dt
import json
import re
import sys
from pathlib import Path

try:
    import plotly.graph_objects as go
except ImportError:
    sys.exit("plotly is not installed. Install it with:  pip install plotly")


# ---------------------------------------------------------------------------
# Config
# ---------------------------------------------------------------------------

# Order = legend order = drawing order (later traces drawn on top).
PRAYERS = ["fajr", "sunrise", "doha", "dhuhar", "asr", "maghrib", "isha"]

DISPLAY_NAMES = {
    "fajr":    "Fajr",
    "sunrise": "Sunrise",
    "doha":    "Doha",
    "dhuhar":  "Dhuhr",
    "asr":     "Asr",
    "maghrib": "Maghrib",
    "isha":    "Isha",
}

# Soft sunset/sunrise palette - walks from twilight -> dawn -> midday -> dusk -> night.
PRAYER_COLORS = {
    "fajr":    "#7c6daa",   # twilight lavender
    "sunrise": "#e9967a",   # soft dawn salmon
    "doha":    "#e8b14e",   # warm amber
    "dhuhar":  "#5fb3a1",   # midday seafoam
    "asr":     "#4a85ad",   # cool afternoon blue
    "maghrib": "#cf5c5c",   # sunset rose
    "isha":    "#2d3561",   # deep night blue
}

# Pretty masjid display labels (falls back to title-cased folder name).
MASJID_DISPLAY_NAMES = {
    "davis":        "Davis",
    "sclaraalnoor": "Santa Clara (Alnoor)",
    "sclaramca":    "Santa Clara (MCA)",
    "woodland":     "Woodland",
}


def display_masjid_name(key):
    return MASJID_DISPLAY_NAMES.get(key, key.replace("_", " ").title())


# Font stack used across the figure.
FONT_FAMILY = "Inter, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, sans-serif"

YEAR_RE = re.compile(r"^\d{4}$")
TIME_RE = re.compile(r"^([01][0-9]|2[0-3]):[0-5][0-9]$")


# ---------------------------------------------------------------------------
# Time helpers
# ---------------------------------------------------------------------------

def parse_time_to_minutes(timestr, prayer):
    """Convert "HH:MM" -> minutes since midnight, applying firmware AM/PM rules.

    Returns None for malformed/empty input so plotly leaves a gap."""
    if not timestr:
        return None
    s = timestr.strip()
    if not TIME_RE.match(s):
        return None
    h = int(s[:2])
    m = int(s[3:5])
    if prayer == "dhuhar":
        if h < 9:
            h += 12
    elif prayer in ("asr", "maghrib", "isha"):
        if h < 12:
            h += 12
    # fajr, sunrise, doha: always AM, no adjustment
    return h * 60 + m


def minutes_to_hhmm(minutes):
    if minutes is None:
        return "--:--"
    h, m = divmod(int(minutes), 60)
    return f"{h:02d}:{m:02d}"


def is_leap(year):
    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)


# ---------------------------------------------------------------------------
# Data loading
# ---------------------------------------------------------------------------

def collect_year_data(year_dir, year):
    """Walk DDD.json files for one year and build per-prayer time series."""
    dates = []
    series = {p: [] for p in PRAYERS}
    hover_times = {p: [] for p in PRAYERS}

    last_day = 366 if is_leap(year) else 365

    for doy in range(1, last_day + 1):
        fpath = year_dir / f"{doy:03d}.json"
        if not fpath.exists():
            continue
        try:
            data = json.loads(fpath.read_text())
        except (json.JSONDecodeError, OSError) as e:
            print(f"  warning: could not read {fpath}: {e}", file=sys.stderr)
            continue

        date = dt.date(year, 1, 1) + dt.timedelta(days=doy - 1)
        dates.append(date)
        for p in PRAYERS:
            mins = parse_time_to_minutes(data.get(p, ""), p)
            series[p].append(mins)
            hover_times[p].append(minutes_to_hhmm(mins))

    return {"dates": dates, "series": series, "hover_times": hover_times}


# ---------------------------------------------------------------------------
# Figure construction
# ---------------------------------------------------------------------------

def build_figure(masjid, year, data):
    fig = go.Figure()

    for prayer in PRAYERS:
        fig.add_trace(
            go.Scatter(
                x=data["dates"],
                y=data["series"][prayer],
                customdata=data["hover_times"][prayer],
                mode="lines+markers",
                name=DISPLAY_NAMES[prayer],
                line=dict(color=PRAYER_COLORS[prayer], width=2.2, shape="linear"),
                marker=dict(size=4, symbol="circle", line=dict(width=0),
                            color=PRAYER_COLORS[prayer]),
                hovertemplate="%{customdata}<extra></extra>",
                connectgaps=False,
            )
        )

    # Y axis: minutes-from-midnight as numeric; show HH:MM tick labels.
    y_tickvals = list(range(0, 24 * 60 + 1, 60))
    y_ticktext = [minutes_to_hhmm(v) for v in y_tickvals]

    # Tighten initial Y range to where prayers actually live, with padding;
    # full 0..1440 grid is still visible when the user zooms out.
    all_mins = [m for series in data["series"].values()
                for m in series if m is not None]
    if all_mins:
        y_min = max(0, min(all_mins) - 60)
        y_max = min(24 * 60, max(all_mins) + 60)
    else:
        y_min, y_max = 0, 24 * 60

    # X axis: explicit ticks on the 1st of each month, labelled "1-Jan".
    x_tickvals = [dt.date(year, m, 1) for m in range(1, 13)]

    masjid_display = display_masjid_name(masjid)

    fig.update_layout(
        title=dict(
            text=(
                f"Prayer Times  ·  <b>{masjid_display}</b> "
                f" ·  {year}"
                f"<br>"
                f"<span style='font-size:12px;color:#6b7280'>"
                f"click a name to toggle · double-click to solo · drag to zoom"
                f"</span>"
            ),
            x=0.5, xanchor="center",
            font=dict(family=FONT_FAMILY, size=22, color="#1f2937"),
        ),
        font=dict(family=FONT_FAMILY, size=12, color="#374151"),
        xaxis=dict(
            title=dict(text="Date", font=dict(size=13, color="#4b5563")),
            type="date",
            tickmode="array",
            tickvals=x_tickvals,
            tickformat="%-d-%b",
            tickangle=-45,
            tickfont=dict(size=11, color="#4b5563"),
            showgrid=True,
            gridcolor="#eef0f3",
            gridwidth=1,
            zeroline=False,
            linecolor="#d1d5db",
            showspikes=True,
            spikemode="across",
            spikesnap="cursor",
            spikedash="dot",
            spikecolor="#9ca3af",
            spikethickness=1,
            rangeselector=dict(
                buttons=[
                    dict(count=1,  label="1m",  step="month", stepmode="backward"),
                    dict(count=3,  label="3m",  step="month", stepmode="backward"),
                    dict(count=6,  label="6m",  step="month", stepmode="backward"),
                    dict(step="all", label="Year"),
                ],
                x=0.0, y=1.08,
                bgcolor="#f3f4f6",
                bordercolor="#e5e7eb",
                borderwidth=1,
                activecolor="#dbeafe",
                font=dict(family=FONT_FAMILY, size=11, color="#374151"),
            ),
            rangeslider=dict(
                visible=True,
                thickness=0.05,
                bgcolor="#f3f4f6",
                bordercolor="#e5e7eb",
            ),
        ),
        yaxis=dict(
            title=dict(text="Time of day (24h)",
                       font=dict(size=13, color="#4b5563")),
            tickmode="array",
            tickvals=y_tickvals,
            ticktext=y_ticktext,
            tickfont=dict(size=11, color="#4b5563"),
            range=[y_min, y_max],
            showgrid=True,
            gridcolor="#eef0f3",
            gridwidth=1,
            zeroline=False,
            linecolor="#d1d5db",
            showspikes=True,
            spikemode="across",
            spikesnap="cursor",
            spikedash="dot",
            spikecolor="#9ca3af",
            spikethickness=1,
        ),
        hovermode="x unified",
        hoverlabel=dict(
            bgcolor="rgba(255,255,255,0.96)",
            bordercolor="#e5e7eb",
            font=dict(family=FONT_FAMILY, size=12, color="#1f2937"),
        ),
        legend=dict(
            title=dict(text="<b>Prayer</b>",
                       font=dict(family=FONT_FAMILY, size=12, color="#1f2937")),
            orientation="v",
            yanchor="top", y=1.0,
            xanchor="left", x=1.02,
            bgcolor="rgba(255,255,255,0.96)",
            bordercolor="#e5e7eb",
            borderwidth=1,
            font=dict(family=FONT_FAMILY, size=12, color="#374151"),
            itemsizing="constant",
        ),
        updatemenus=[
            dict(
                type="buttons",
                direction="right",
                pad=dict(r=4, t=4),
                showactive=False,
                x=1.0, xanchor="right",
                y=1.08, yanchor="bottom",
                bgcolor="#f3f4f6",
                bordercolor="#e5e7eb",
                borderwidth=1,
                font=dict(family=FONT_FAMILY, size=11, color="#374151"),
                buttons=[
                    dict(label="Show all",
                         method="restyle",
                         args=[{"visible": [True] * len(PRAYERS)}]),
                    dict(label="Hide all",
                         method="restyle",
                         args=[{"visible": ["legendonly"] * len(PRAYERS)}]),
                ],
            ),
        ],
        template="plotly_white",
        paper_bgcolor="#ffffff",
        plot_bgcolor="#fbfbfd",
        margin=dict(l=80, r=180, t=120, b=80),
        autosize=True,
    )
    return fig


# ---------------------------------------------------------------------------
# Driver
# ---------------------------------------------------------------------------

def process_base(base):
    if not base.is_dir():
        print(f"error: not a directory: {base}", file=sys.stderr)
        return 1

    written = 0
    masjid_dirs = sorted(p for p in base.iterdir() if p.is_dir())
    if not masjid_dirs:
        print(f"error: no subdirectories under {base}", file=sys.stderr)
        return 1

    for masjid_dir in masjid_dirs:
        year_dirs = sorted(p for p in masjid_dir.iterdir()
                           if p.is_dir() and YEAR_RE.match(p.name))
        if not year_dirs:
            print(f"skipping {masjid_dir.name}: no <year>/ subdirs found")
            continue

        for year_dir in year_dirs:
            year = int(year_dir.name)
            print(f"processing {masjid_dir.name}/{year} ...")
            data = collect_year_data(year_dir, year)
            if not data["dates"]:
                print(f"  no daily JSON files found, skipping")
                continue
            fig = build_figure(masjid_dir.name, year, data)
            out_path = masjid_dir / f"prayers_plots_{year}.html"
            fig.write_html(
                str(out_path),
                include_plotlyjs="cdn",
                full_html=True,
                config={
                    "responsive": True,
                    "displaylogo": False,
                    "scrollZoom": True,
                    "toImageButtonOptions": {
                        "filename": f"prayers_{masjid_dir.name}_{year}",
                        "format": "png",
                        "scale": 2,
                    },
                },
            )
            print(f"  wrote {out_path}  ({len(data['dates'])} days)")
            written += 1

    if written == 0:
        print("no <masjid>/<year>/ subdirectories produced output.",
              file=sys.stderr)
        return 1
    print(f"done. wrote {written} HTML file(s).")
    return 0


def main():
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument("base",
                    help="path to the prayer-times base directory "
                         "(e.g. docs/athantimes)")
    args = ap.parse_args()
    sys.exit(process_base(Path(args.base).expanduser().resolve()))


if __name__ == "__main__":
    main()

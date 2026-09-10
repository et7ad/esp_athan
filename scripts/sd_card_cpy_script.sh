#!/bin/bash

######################################################################
# SD‑card copy helper for the Athan clock (DFPlayer Mini audio)
#
# Use case
# ----------------------
# The DFPlayer does NOT use filenames; it plays files by the order in
# which they were copied to the SD‑card (first copied => track 1,
# second => track 2, etc.). To make sure the Athan clock firmware and
# the README’s file‑number assumptions stay correct, we need a
# repeatable way to copy the audio files in a known, stable order.
#
# What it does
# ------------
# 1. Copies A1–A10 first  -> become files 1–10  (Athan audios, regular wording).
# 2. Copies B1–B10 next   -> become files 11–20 (hourly tick range).
# 3. Copies C1–C4 next    -> become files 21–24 (UI / menu sounds).
# 4. Copies all D*.mp3    -> become files 25–34 (Quyam audio, picked at random).
# 5. Copies F1–F10 next   -> become files 35–44 (Fajr-wording athans; F<k> pairs with A<k>).
# 6. Copies all Z*.mp3    -> become files 45–48 (fallback message; MUST be last).
#
# How to use it
# -------------
# 1. Format the SD‑card as FAT16/FAT32 and make sure it is empty.
# 2. Mount the card (on macOS it appears under /Volumes/NAME).
# 3. Set SRC below to the folder that contains A1.mp3, B1.mp3, etc.
# 4. Set DEST to the root folder of the mounted SD‑card.
# 5. Run:  bash sd_card_cpy_script.sh
# 6. (macOS) Afterwards, run `ls -al` on the SD‑card root to verify
#    there are no extra `._*` or `.DS_Store` files; if there are,
#    remove them using the cleanup command mentioned in README.md
#    so the DFPlayer only sees the intended audio files.
#
# After this, the SD‑card will have the files in the exact order that
# the firmware expects, matching the layout described in README.md
# (section “SD‑card for audio (DFPlayer)”).

# Source and destination folders (edit these for your machine)
SRC="/Path/To/Source/AudioFiles"
DEST="/Path/To/Destination/SDCard"


# Copy A1–A10
for i in {1..10}; do
    cp "$SRC/A$i.mp3" "$DEST/"
done

# Copy B1–B10
for i in {1..10}; do
    cp "$SRC/B$i.mp3" "$DEST/"
done

# Copy C1–C4
for i in {1..4}; do
    cp "$SRC/C$i.mp3" "$DEST/"
done

# Copy all D files (D1, D2, D3… automatically) -> files 25-34 (order does not matter, picked at random)
for f in "$SRC"/D*.mp3; do
    cp "$f" "$DEST/"
done

# Copy F1–F10 (Fajr-wording athans) -> files 35–44. F<k> is the Fajr version of A<k>.
for i in {1..10}; do
    cp "$SRC/F$i.mp3" "$DEST/"
done

# Copy all Z files (fallback message) -> files 45-48. MUST stay last.
for f in "$SRC"/Z*.mp3; do
    cp "$f" "$DEST/"
done


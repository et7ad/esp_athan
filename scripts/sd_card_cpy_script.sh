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


# On macOS, plain `cp` also copies extended attributes (quarantine flag, Finder tags...). A FAT card
# cannot hold them, so macOS writes a hidden "._name.mp3" sidecar next to each file. The DFPlayer
# counts those as tracks and, because FAT reuses the first free directory slot, a sidecar written
# after cleanup can land between real files and shift every track number. `cp -X` never creates them.
CP="cp"
if [ "$(uname)" = "Darwin" ]; then CP="cp -X"; fi

# Safety: the cleanup below deletes hidden folders, so refuse to run unless DEST is a mounted card.
if [ ! -d "$DEST" ] || [ "$DEST" = "/" ] || { [ "$(uname)" = "Darwin" ] && [[ "$DEST" != /Volumes/* ]]; }; then
    echo "DEST='$DEST' is not a mounted SD card (expected something like /Volumes/AUDIO). Aborting."
    exit 1
fi

# Keep macOS from indexing or logging on this card. Spotlight looks for .metadata_never_index BEFORE
# it creates its .Spotlight-V100 store, and the event logger skips a card whose .fseventsd folder holds
# a file named no_log. Both markers STAY on the card on purpose: they are tiny, have no audio
# extension (the DFPlayer only counts .mp3/.wav/.wma files), and they mean that mounting the card on
# a Mac again creates nothing. Deleting a live .Spotlight-V100 instead leaves orphaned FAT entries
# behind (seen as a bogus "._F6.mp3" directory). Do NOT use `mdutil -i off`: it stores its setting
# inside .Spotlight-V100, which is exactly the folder we do not want.
if [ "$(uname)" = "Darwin" ]; then
    touch "$DEST/.metadata_never_index"
    mkdir -p "$DEST/.fseventsd" && touch "$DEST/.fseventsd/no_log"
fi

# Copy A1–A10
for i in {1..10}; do
    $CP "$SRC/A$i.mp3" "$DEST/"
done

# Copy B1–B10
for i in {1..10}; do
    $CP "$SRC/B$i.mp3" "$DEST/"
done

# Copy C1–C4
for i in {1..4}; do
    $CP "$SRC/C$i.mp3" "$DEST/"
done

# Copy all D files (D1, D2, D3… automatically) -> files 25-34 (order does not matter, picked at random)
for f in "$SRC"/D*.mp3; do
    $CP "$f" "$DEST/"
done

# Copy F1–F10 (Fajr-wording athans) -> files 35–44. F<k> is the Fajr version of A<k>.
for i in {1..10}; do
    $CP "$SRC/F$i.mp3" "$DEST/"
done

# Copy all Z files (fallback message) -> files 45-48. MUST stay last.
for f in "$SRC"/Z*.mp3; do
    $CP "$f" "$DEST/"
done

# Cleanup of everything macOS may still have added, repeated until the card stays clean (macOS can
# re-create a sidecar moments after it was deleted), then verify, then eject right away.
# Kept on purpose: .metadata_never_index and .fseventsd/no_log (see above).
if [ "$(uname)" = "Darwin" ]; then
    dot_clean -m "$DEST" 2>/dev/null
    for round in 1 2 3 4 5; do
        rm -rf "$DEST"/.DS_Store "$DEST"/.Trashes "$DEST"/._* 2>/dev/null
        sync
        sleep 1
        if ! ls -d "$DEST"/._* "$DEST"/.DS_Store "$DEST"/.Trashes >/dev/null 2>&1; then break; fi
        echo "cleanup round $round: macOS re-created hidden entries, deleting again"
    done
fi
sync
echo
echo "Files on the card (A1-A10, B1-B10, C1-C4, D1-D10, F1-F10, Z_fallback_1-4 = 48 mp3s; plus the two markers):"
ls -la "$DEST"
echo
echo "mp3 files: $(ls "$DEST" | grep -ci '\.mp3$')   (expected 48)"
if ls -d "$DEST"/._* >/dev/null 2>&1; then
    echo "WARNING: ._ entries are still present after 5 cleanup rounds. Do not use this card: format it again and rerun this script."
    exit 1
fi
if [ -d "$DEST/.Spotlight-V100" ]; then
    echo "NOTE: .Spotlight-V100 exists, so Spotlight started before the marker was in place. It is a folder and harmless, but for a"
    echo "      clean card: format again and run this script immediately after the card mounts, before anything else touches it."
fi
if [ "$(uname)" = "Darwin" ]; then
    diskutil unmount "$DEST" && echo "Card ejected. Remove it now; do not remount it on the Mac (that would recreate the hidden folders)."
else
    echo "Now eject the card without opening it in a file manager."
fi

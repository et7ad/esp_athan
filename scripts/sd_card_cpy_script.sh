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
# 0. Formats the card the way the DFPlayer needs it (see "Why the format step").
#    Linux: lists the removable disks, asks which one is the card, then wipes it,
#    creates one partition and formats it. macOS: formats the volume at DEST.
# 1. Copies A1–A10 first  -> become files 1–10  (Athan audios, regular wording).
# 2. Copies B1–B10 next   -> become files 11–20 (hourly tick range).
# 3. Copies C1–C4 next    -> become files 21–24 (UI / menu sounds).
# 4. Copies all D*.mp3    -> become files 25–34 (Quyam audio, picked at random).
# 5. Copies F1–F10 next   -> become files 35–44 (Fajr-wording athans; F<k> pairs with A<k>).
# 6. Copies all Z*.mp3    -> become files 45–48 (fallback message; MUST be last).
# 7. Removes what the OS added, then reads the card's raw directory the way the
#    DFPlayer reads it and prints the 48 tracks in the order the module will see.
#    It refuses the card if that order is wrong or if any track is out of the
#    module's reach.
#
# How to use it
# -------------
# 1. Put the card in the computer. Whatever is on it will be erased.
# 2. Set SRC below to the folder that contains A1.mp3, B1.mp3, etc.
# 3. macOS only: set DEST to the mounted card (for example /Volumes/AUDIO).
#    Linux ignores DEST: the script shows the removable disks and asks which one is
#    the card. It needs sudo for the disk work and asks for your password once.
# 4. Run:  bash sd_card_cpy_script.sh   and answer YES when it asks to erase/format.
# 5. Read its last lines: the track table must end with "Card is good", then the
#    card is ejected. Do not mount it on the computer again; put it in the DFPlayer.
#
# To only LOOK at a card (nothing is written):  INSPECT=yes bash sd_card_cpy_script.sh
# It prints the card's directory as the DFPlayer counts it, so a card that plays the
# wrong track or nothing for some number can be diagnosed without redoing it.
#
# Why the format step (the Fajr 7–10 bug of 2026-09-15)
# ------------------------------------------------------
# On a FAT card the DFPlayer walks the root directory slot by slot (32 bytes each) and
# numbers the audio files it meets. On macOS every file a Terminal command creates on
# a FAT card also gets a hidden twin "._name" (macOS stores its com.apple.provenance
# attribute there; cp -X, cat, touch, mkdir all trigger it, nothing prevents it).
# The cleanup below deletes the twins, but a deleted entry keeps its slots, so every
# audio file costs 3 slots: 48 files + the two marker files = 165 slots. A card that
# Disk Utility (or Windows) formatted with the default 4 KB allocation block has only
# 128 slots in the first block of the root directory, and cheap DFPlayer modules do
# not read the directory past its first block: tracks 41–48 (Fajr athans 7–10 and the
# fallback message) exist for the Mac but not for the module. Firmware V5 had 38
# files (123 slots) and stayed just under the limit; V6 crossed it. Linux creates no
# twins (about 57 slots), but a card that was reused without formatting keeps every
# dead slot and every leftover entry of its earlier life, so its layout is anyone's
# guess. Hence: always format, always verify.
# 32 KB blocks give the root directory 1024 slots, so the layout can never spill.
# FAT16 (cards of 2 GB and smaller) has a fixed 512-slot root directory and is fine.
#
# The verification at the end reads the raw device, so it checks what the module
# sees, not what a file manager shows. Trust it over `ls`.

# Source folder (edit this for your machine)
SRC="/Path/To/Source/AudioFiles"
# macOS only: the mounted card. Linux ignores it (the script asks which disk is the card).
DEST="/Path/To/Destination/SDCard"

# FORMAT (macOS): "ask" (default; asks once, needs a terminal), "yes" (format without asking),
# "no" (keep the card's current file system; the final check still guards the layout).
# On Linux the card is always erased; FORMAT=yes only skips the YES confirmation.
FORMAT="${FORMAT:-ask}"
# INSPECT: "yes" = read-only; print what the DFPlayer sees on the card and stop.
INSPECT="${INSPECT:-no}"
# DISK (Linux): preselect the card, e.g. DISK=/dev/sdb, instead of choosing from the list.
DISK="${DISK:-}"

case "$(uname)" in
    Darwin) IS_MAC=1; IS_LINUX=0 ;;
    Linux)  IS_MAC=0; IS_LINUX=1 ;;
    *) echo "Only macOS and Linux are supported."; exit 1 ;;
esac
SUDO=""; [ $IS_LINUX = 1 ] && [ "$(id -u)" != 0 ] && SUDO="sudo"

for f in A1 B1 C1 F1; do
    if [ ! -f "$SRC/$f.mp3" ]; then echo "SRC='$SRC' has no $f.mp3. Set SRC to the folder with the audio files. Aborting."; exit 1; fi
done

PY=$(command -v python3 || true); [ -z "$PY" ] && [ -x /usr/bin/python3 ] && PY=/usr/bin/python3
fail() { echo "$1 Aborting."; exit 1; }

######################################################################
# Linux: choose the card, erase it, partition + format it, mount it.
######################################################################
linux_pick_disk() {
    # Candidates: removable disks or USB/SD-reader transports; never the disk that holds "/".
    local rootsrc rootdisk line NAME SIZE RM TRAN TYPE MODEL mounts i n
    rootsrc=$(findmnt -no SOURCE / 2>/dev/null)
    rootdisk=$(lsblk -no PKNAME "$rootsrc" 2>/dev/null | head -1)
    CANDIDATES=()
    while IFS= read -r line; do
        NAME=""; SIZE=""; RM=""; TRAN=""; TYPE=""; MODEL=""
        eval "$line"
        [ "$TYPE" = "disk" ] || continue
        [ -n "$rootdisk" ] && [ "$NAME" = "/dev/$rootdisk" ] && continue
        case "$TRAN" in usb|mmc) ;; *) [ "$RM" = "1" ] || continue ;; esac
        mounts=$(lsblk -nrpo MOUNTPOINT "$NAME" 2>/dev/null | grep -v '^$' | paste -sd ' ' -)
        CANDIDATES+=("$NAME|$SIZE|${TRAN:-?}|${MODEL:-}|${mounts:+mounted at $mounts}")
    done < <(lsblk -dnpP -o NAME,SIZE,RM,TRAN,TYPE,MODEL 2>/dev/null)

    if [ -n "$DISK" ]; then
        [ -b "$DISK" ] || fail "DISK='$DISK' is not a block device."
        [ -n "$rootdisk" ] && [ "$DISK" = "/dev/$rootdisk" ] && fail "DISK='$DISK' holds your system."
        return
    fi
    [ ${#CANDIDATES[@]} -gt 0 ] || fail "No removable disk found. Plug the card in (or its reader) and rerun, or run with DISK=/dev/sdX."
    [ -t 0 ] || fail "No terminal to ask on. Run with DISK=/dev/sdX to name the card."
    echo
    echo "Removable disks:"
    n=${#CANDIDATES[@]}
    for i in $(seq 1 "$n"); do
        IFS='|' read -r NAME SIZE TRAN MODEL mounts <<< "${CANDIDATES[$((i-1))]}"
        printf "  %d) %-14s %7s  %-4s %s  %s\n" "$i" "$NAME" "$SIZE" "$TRAN" "$MODEL" "$mounts"
    done
    printf "Which one is the SD card? Type its number (q to quit): "
    read -r answer
    [[ "$answer" =~ ^[0-9]+$ ]] && [ "$answer" -ge 1 ] && [ "$answer" -le "$n" ] || fail "No card chosen."
    DISK=${CANDIDATES[$((answer-1))]%%|*}
}

linux_first_partition() {
    lsblk -lnpo NAME,TYPE "$DISK" 2>/dev/null | awk '$2=="part"{print $1; exit}'
}

linux_umount_all() {
    # Unmount by device node (a mount point with spaces would break unmounting by path); the disk itself
    # can be mounted too (a card without partition table). Desktop automounters re-mount on every change,
    # so this is called before each step that needs the card free.
    local p
    for p in $(lsblk -lnpo NAME "$DISK" 2>/dev/null); do
        while findmnt -no TARGET "$p" >/dev/null 2>&1; do
            $SUDO umount "$p" 2>/dev/null || return 1
        done
    done
}

linux_prepare() {
    for t in lsblk findmnt wipefs sfdisk; do command -v "$t" >/dev/null || fail "'$t' is missing (package util-linux)."; done
    MKFS=$(command -v mkfs.fat || command -v mkfs.vfat || true)
    [ "$INSPECT" = "yes" ] || [ -n "$MKFS" ] || fail "mkfs.fat is missing: install dosfstools (e.g. sudo apt install dosfstools)."
    linux_pick_disk
    local bytes size model mkfs_args ptype need m
    bytes=$(lsblk -dbno SIZE "$DISK"); size=$(lsblk -dno SIZE "$DISK"); model=$(lsblk -dno MODEL "$DISK" | sed 's/ *$//')
    echo "Card: $DISK ($size${model:+, $model})"

    if [ "$INSPECT" = "yes" ]; then
        echo "INSPECT=yes: nothing will be written to the card."
        PART=$(linux_first_partition); [ -n "$PART" ] || PART="$DISK"     # no partition table: the file system is on the disk itself
        sync
        DEST=$(findmnt -no TARGET "$PART" 2>/dev/null | head -1)   # may be empty; only used for the ls count
        return
    fi

    # FAT16 for 2 GB and smaller (fixed 512-slot root directory), FAT32 with 32 KB blocks above.
    if [ "$bytes" -le 2147483648 ]; then mkfs_args="-F 16"; ptype="6"; need="FAT16"; else mkfs_args="-F 32 -s 64"; ptype="c"; need="FAT32 with 32 KB blocks"; fi
    if [ "$bytes" -gt 34359738368 ]; then echo "NOTE: cards above 32 GB are outside the DFPlayer's specification; a smaller card is safer."; fi

    if [ "$FORMAT" != "yes" ]; then
        [ -t 0 ] || fail "No terminal to confirm on. Run with FORMAT=yes to erase $DISK without asking."
        echo
        echo "EVERYTHING on $DISK ($size${model:+, $model}) will be erased, whatever its name or content, and it will be"
        echo "partitioned and formatted as $need."
        printf "Type YES to continue, anything else to quit: "
        read -r answer
        [ "$answer" = "YES" ] || fail "Not confirmed."
    fi
    [ -n "$SUDO" ] && echo "(sudo is needed for the disk work; enter your password if asked)"
    linux_umount_all || fail "Could not unmount the card. Close whatever uses it and rerun."
    echo "Erasing and partitioning $DISK ..."
    # Wipe the signatures inside the old partitions first: the new partition usually starts at the same
    # place, and an old FAT boot sector left there would be re-detected (and auto-mounted) the moment
    # sfdisk creates it, which makes mkfs.fat refuse the partition.
    for m in $(lsblk -lnpo NAME "$DISK" | tail -n +2); do $SUDO wipefs -aq "$m" >/dev/null 2>&1; done
    $SUDO wipefs -aq "$DISK" >/dev/null || fail "wipefs failed."
    printf 'label: dos\n,,%s\n' "$ptype" | $SUDO sfdisk -q "$DISK" >/dev/null || fail "sfdisk failed."
    $SUDO udevadm settle 2>/dev/null; sleep 1
    PART=$(linux_first_partition)
    [ -n "$PART" ] && [ -b "$PART" ] || fail "The new partition did not show up on $DISK."
    linux_umount_all || fail "Could not unmount the new partition."
    echo "Formatting $PART as $need, label AUDIO ..."
    # shellcheck disable=SC2086
    if ! $SUDO "$MKFS" $mkfs_args -n AUDIO "$PART" >/dev/null 2>&1; then
        # A card just over 2 GB can have too few 32 KB clusters for FAT32; 16 KB blocks (512 slots) are still plenty.
        [ "$ptype" = "c" ] && $SUDO "$MKFS" -F 32 -s 32 -n AUDIO "$PART" >/dev/null 2>&1 || fail "mkfs.fat failed."
    fi
    $SUDO udevadm settle 2>/dev/null; sleep 1
    # A desktop automounter may have grabbed the fresh file system; take it back and mount it ourselves.
    linux_umount_all || fail "Could not unmount the freshly formatted partition."
    MNT=$(mktemp -d "${TMPDIR:-/tmp}/sdcard_mnt.XXXXXX")
    $SUDO mount -o "uid=$(id -u),gid=$(id -g),umask=022" "$PART" "$MNT" || fail "Could not mount $PART."
    DEST="$MNT"
}

linux_unmount() {
    sync
    if [ -n "$MNT" ]; then $SUDO umount "$MNT" 2>/dev/null; rmdir "$MNT" 2>/dev/null; MNT=""; fi
    linux_umount_all
}

######################################################################
# macOS: find the device behind DEST and (optionally) format it.
######################################################################
mac_prepare() {
    DEST="${DEST%/}"
    # Safety: the steps below erase and clean the card, so refuse anything that is not a mounted card.
    if [ ! -d "$DEST" ] || [ "$DEST" = "/" ] || [[ "$DEST" != /Volumes/* ]]; then
        fail "DEST='$DEST' is not a mounted SD card (expected something like /Volumes/AUDIO)."
    fi
    local INFO VOLNAME BLOCK FS BYTES NEWFS_ARGS NEED DO_FORMAT LABEL
    INFO=$(diskutil info "$DEST" 2>/dev/null)
    DEV=$(echo "$INFO" | awk -F': *' '/Device Node/{print $2}')
    WHOLE=$(echo "$INFO" | awk -F': *' '/Part of Whole/{print $2}')
    VOLNAME=$(echo "$INFO" | awk -F': *' '/Volume Name/{print $2}')
    BLOCK=$(echo "$INFO" | awk -F': *' '/Allocation Block Size/{print $2+0}')
    FS=$(echo "$INFO" | awk -F': *' '/File System Personality/{print $2}')
    BYTES=$(diskutil info "$DEV" 2>/dev/null | awk '/Disk Size/{match($0,/\(([0-9]+) Bytes\)/); print substr($0,RSTART+1,RLENGTH-8)}')
    [ -n "$DEV" ] && [ -n "$BYTES" ] || fail "Could not identify the device behind $DEST (diskutil info failed)."
    RDEV="/dev/r${DEV#/dev/}"
    echo "Card: $DEST is $DEV ($((BYTES/1000000)) MB, $FS, ${BLOCK:-?} B allocation blocks)"

    # FAT16 for 2 GB and smaller (fixed 512-slot root directory), FAT32 with 32 KB blocks above.
    if [ "$BYTES" -le 2147483648 ]; then NEWFS_ARGS="-F 16"; NEED="FAT16"; else NEWFS_ARGS="-F 32 -c 64"; NEED="FAT32 with 32 KB blocks"; fi
    if [ "$BYTES" -gt 34359738368 ]; then echo "NOTE: cards above 32 GB are outside the DFPlayer's specification; a smaller card is safer."; fi

    DO_FORMAT=0
    if [ "$INSPECT" = "yes" ]; then
        echo "INSPECT=yes: nothing will be written to the card."
    else
        case "$FORMAT" in
            yes) DO_FORMAT=1 ;;
            no)  echo "FORMAT=no: keeping the card's current file system." ;;
            *)
                if [ -t 0 ]; then
                    echo
                    echo "Format $DEV ($VOLNAME) as $NEED first? This ERASES the card. Recommended: a fresh card is the"
                    echo "only way to be sure the DFPlayer sees all 48 tracks (see the header of this script)."
                    printf "Type YES to format, anything else to keep the current file system: "
                    read -r answer
                    [ "$answer" = "YES" ] && DO_FORMAT=1
                else
                    echo "No terminal to ask on; not formatting (run with FORMAT=yes to format, FORMAT=no to silence this)."
                fi ;;
        esac
    fi
    if [ $DO_FORMAT = 1 ]; then
        LABEL=$(echo "$VOLNAME" | tr '[:lower:]' '[:upper:]' | tr -cd 'A-Z0-9_-' | cut -c1-11)
        [ -z "$LABEL" ] && LABEL="AUDIO"
        diskutil unmount "$DEV" >/dev/null || fail "Could not unmount $DEV. Close whatever uses the card and rerun."
        echo "Formatting $RDEV as $NEED, label $LABEL ..."
        # shellcheck disable=SC2086
        if ! newfs_msdos $NEWFS_ARGS -v "$LABEL" "$RDEV" >/dev/null 2>&1; then
            echo "newfs_msdos needs more rights on this device; asking for your password."
            # shellcheck disable=SC2086
            sudo newfs_msdos $NEWFS_ARGS -v "$LABEL" "$RDEV" || fail "Formatting failed."
        fi
        diskutil mount "$DEV" >/dev/null || fail "Could not mount $DEV after formatting."
        DEST=$(diskutil info "$DEV" | awk -F': *' '/Mount Point/{print $2}')
        [ -d "$DEST" ] || fail "Card did not come back after formatting."
        echo "Formatted; card is now mounted at $DEST"
    fi
}

DEV=""; WHOLE=""; RDEV=""; PART=""; MNT=""
if [ $IS_MAC = 1 ]; then mac_prepare; else linux_prepare; fi

# Keep macOS from indexing or logging on this card, should it ever be mounted on a Mac. Spotlight looks for
# .metadata_never_index BEFORE it creates its .Spotlight-V100 store, and the event logger skips a card whose
# .fseventsd folder holds a file named no_log. Both markers STAY on the card on purpose: they are tiny, have no
# audio extension (the DFPlayer only counts .mp3/.wav/.wma files), and they mean that mounting the card on a
# Mac creates nothing. Deleting a live .Spotlight-V100 instead leaves orphaned FAT entries behind (seen as a
# bogus "._F6.mp3" directory). Do NOT use `mdutil -i off`: it stores its setting inside .Spotlight-V100.
if [ "$INSPECT" != "yes" ]; then
    touch "$DEST/.metadata_never_index"
    mkdir -p "$DEST/.fseventsd" && touch "$DEST/.fseventsd/no_log"
fi

######################################################################
# Copy, in the order the firmware expects. ORDER_FILE records it for the check.
######################################################################
ORDER_FILE=$(mktemp "${TMPDIR:-/tmp}/sdcard_order.XXXXXX")
copy_one() {
    if [ "$INSPECT" != "yes" ]; then
        if [ $IS_MAC = 1 ]; then cp -X "$1" "$DEST/"; else cp "$1" "$DEST/"; fi || fail "Copy of $1 failed."
    fi
    basename "$1" >> "$ORDER_FILE"
}

for i in {1..10}; do copy_one "$SRC/A$i.mp3"; done        # A1–A10 -> 1–10
for i in {1..10}; do copy_one "$SRC/B$i.mp3"; done        # B1–B10 -> 11–20
for i in {1..4};  do copy_one "$SRC/C$i.mp3"; done        # C1–C4  -> 21–24
for f in "$SRC"/D*.mp3; do copy_one "$f"; done            # D*     -> 25–34 (any order, picked at random)
for i in {1..10}; do copy_one "$SRC/F$i.mp3"; done        # F1–F10 -> 35–44
for f in "$SRC"/Z*.mp3; do copy_one "$f"; done            # Z*     -> 45–48, MUST stay last

######################################################################
# macOS: cleanup of everything it added, repeated until the card stays clean (macOS can
# re-create a twin moments after it was deleted). Kept: the two markers (see above).
######################################################################
if [ $IS_MAC = 1 ] && [ "$INSPECT" != "yes" ]; then
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
if [ -n "$DEST" ] && [ -d "$DEST" ]; then
    echo
    echo "mp3 files as the computer sees them: $(ls "$DEST" | grep -ci '\.mp3$')   (expected 48)"
fi
if [ $IS_MAC = 1 ] && [ "$INSPECT" != "yes" ] && ls -d "$DEST"/._* >/dev/null 2>&1; then
    echo "WARNING: ._ entries are still present after 5 cleanup rounds. Do not use this card: rerun this script and format."
    rm -f "$ORDER_FILE"; exit 1
fi

######################################################################
# The real check: read the raw FAT root directory the way the DFPlayer does.
######################################################################
if [ $IS_MAC = 1 ]; then
    diskutil unmount "$DEST" >/dev/null || { echo "Could not unmount the card for the check. Aborting."; rm -f "$ORDER_FILE"; exit 1; }
    CHECK_DEV="$RDEV"; CHECK_SUDO=""
else
    [ "$INSPECT" = "yes" ] || linux_unmount
    CHECK_DEV="$PART"; CHECK_SUDO="$SUDO"      # block devices are root-only on Linux
fi

CHECK_PY=$(mktemp "${TMPDIR:-/tmp}/sdcard_check.XXXXXX")
cat > "$CHECK_PY" <<'PYEOF'
import struct, sys
dev, order_file = sys.argv[1], sys.argv[2]
expected = [l.strip() for l in open(order_file) if l.strip()]
try:
    img = open(dev, 'rb')
except PermissionError:
    print(f"Cannot read {dev} (permission). Run:  sudo python3 {sys.argv[0]} {dev} {order_file}"); sys.exit(2)
ALIGN = 4096                                     # raw devices only accept aligned reads
def read_at(off, n):
    start = off - off % ALIGN
    img.seek(start); b = img.read(((off + n - start + ALIGN - 1) // ALIGN) * ALIGN)
    return b[off - start:off - start + n]
bs = read_at(0, 512)
bps, spc, rsvd, nfats = struct.unpack_from('<HBHB', bs, 11)
root_ent16 = struct.unpack_from('<H', bs, 17)[0]
spf = struct.unpack_from('<H', bs, 22)[0] or struct.unpack_from('<I', bs, 36)[0]
root_clus = struct.unpack_from('<I', bs, 44)[0]
if bps not in (512, 1024, 2048, 4096) or spc == 0 or nfats == 0 or spf == 0:
    print("This does not look like a FAT card (no valid boot sector). Format it and rerun."); sys.exit(2)
cluster_bytes = spc * bps
fat_start = rsvd * bps
data_start = fat_start + nfats * spf * bps + root_ent16 * 32
def fat_next(c):
    return struct.unpack('<I', read_at(fat_start + c * 4, 4))[0] & 0x0FFFFFFF
if root_ent16:                                   # FAT12/16: fixed root directory
    fs = "FAT16"
    blocks = [read_at(fat_start + nfats * spf * bps, root_ent16 * 32)]
    first_block_slots = root_ent16
else:                                            # FAT32: root directory is a cluster chain
    fs = "FAT32"
    blocks, c, seen = [], root_clus, set()
    while 2 <= c < 0x0FFFFFF8 and c not in seen and len(seen) < 64:
        seen.add(c); blocks.append(read_at(data_start + (c - 2) * cluster_bytes, cluster_bytes)); c = fat_next(c)
    first_block_slots = cluster_bytes // 32
tracks, others, slot, used, dead, lfn = [], [], 0, 0, 0, []
done = False
for b in blocks:
    for i in range(0, len(b), 32):
        e = b[i:i + 32]
        if e[0] == 0x00: done = True; break
        used = slot + 1
        if e[0] == 0xE5: lfn = []; dead += 1; slot += 1; continue
        if e[11] == 0x0F:
            lfn.insert(0, (e[1:11] + e[14:26] + e[28:32]).decode('utf-16le', 'replace').split('\x00')[0]); slot += 1; continue
        short = e[0:8].decode('latin1').rstrip() + ('.' + e[8:11].decode('latin1').rstrip() if e[8:11].strip() else '')
        name = ''.join(lfn) or short; lfn = []
        size = struct.unpack_from('<I', e, 28)[0]
        kind = 'label' if e[11] & 0x08 else ('folder' if e[11] & 0x10 else 'file')
        audio = name.lower().endswith(('.mp3', '.wav', '.wma'))
        if kind == 'file' and audio:
            tracks.append((slot, name, size))
        else:
            others.append((slot, name, kind, audio))
        slot += 1
    if done: break
print(f"DFPlayer view of the card ({fs}, {cluster_bytes // 1024} KB blocks, root directory: {used} slots used, {dead} of them dead, first block holds {first_block_slots}):")
ok = True
for n, (s, name, size) in enumerate(tracks, 1):
    exp = expected[n - 1] if n <= len(expected) else '(nothing)'
    flag = ''
    if s >= first_block_slots: flag += '  <-- beyond the first block: NOT playable'; ok = False
    if name.startswith('._'): flag += '  <-- macOS twin counted as a track'; ok = False
    elif name.lower() != exp.lower(): flag += f'  <-- expected {exp}'; ok = False
    print(f"  track {n:2d}  slot {s:3d}  {name}  ({size} bytes){flag}")
for s, name, kind, audio in others:
    note = ''
    if audio: note = '  <-- a folder with an audio name; some modules count it as a track'; ok = False
    elif name.startswith('._'): note = '  <-- leftover macOS twin'
    print(f"  ({kind:6s}) slot {s:3d}  {name}{note}")
if len(tracks) != len(expected):
    print(f"PROBLEM: {len(tracks)} audio files on the card, expected {len(expected)}."); ok = False
if not ok:
    print("PROBLEM: the DFPlayer would not see the tracks the firmware expects. Rerun this script and let it format the card.")
    if fs == "FAT32" and cluster_bytes < 32768:
        print(f"         (this card has {cluster_bytes // 1024} KB blocks; the script formats with 32 KB blocks, which cannot spill)")
    sys.exit(1)
print("Card is good: all tracks are in the first block of the root directory and in the expected order.")
PYEOF

finish_ok() {
    if [ $IS_MAC = 1 ]; then
        diskutil eject "$WHOLE" >/dev/null 2>&1 && echo "Card ejected. Remove it now; do not mount it on the Mac again."
    else
        linux_unmount
        $SUDO eject "$DISK" >/dev/null 2>&1
        echo "Card ejected. Remove it now; do not mount it on the computer again."
    fi
}

if [ -n "$PY" ] && [ -n "$CHECK_DEV" ]; then
    echo
    $CHECK_SUDO "$PY" "$CHECK_PY" "$CHECK_DEV" "$ORDER_FILE"; rc=$?
    rm -f "$CHECK_PY" "$ORDER_FILE"
    if [ "$INSPECT" = "yes" ]; then
        [ $IS_MAC = 1 ] && diskutil mount "$DEV" >/dev/null 2>&1
        echo "Inspect only: nothing was changed."
        exit $rc
    fi
    if [ $rc -ne 0 ]; then
        [ $IS_LINUX = 1 ] && linux_unmount
        echo "The card was NOT ejected so you can rerun the script. Do not use it in the clock."
        exit 1
    fi
    finish_ok
else
    rm -f "$CHECK_PY" "$ORDER_FILE"
    echo "python3 not found: the raw-directory check was skipped, so only the file count above was verified."
    if [ "$INSPECT" = "yes" ]; then [ $IS_MAC = 1 ] && diskutil mount "$DEV" >/dev/null 2>&1; exit 1; fi
    finish_ok
fi

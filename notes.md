## Project notes

This file collects a few practical notes that do not quite belong in the main README but are still useful when assembling or debugging the device.

The MCU is an ESP8266, powered from 3.3 V via a regulator, and most audio‑related parts prefer a clean 5 V rail.

---

## DFPlayer / MP3 module

Connectivity (as used by `athan.yaml`):

| Module pin / signal | Connected to (MC / peripheral) | Direction | Notes |
|---------------------|---------------------------------|----------:|-------|
| TX (module)         | MCU RX (`GPIO3`)               |  Out → In | Serial TX from module to MCU RX |
| RX (module)         | MCU TX (`GPIO1`)               |  In ← Out | Serial RX to module from MCU TX |
| VCC / VIN           | 5 V (external)                 |     Power | Prefer external 5 V supply, not the 3.3 V regulator |
| GND                 | GND                            |     Power | Common ground for module, MCU and supply |

Audio outputs (to amplifier or speaker module) are not fixed in this repo and depend on your chosen hardware, but in general you route the DFPlayer’s audio outputs to your amplifier, then from the amplifier to the speaker.

### Preparing the microSD card (important)

The DFPlayer uses simple numeric file indices. For this project the exact mapping is described in the main `README.md`, but all mappings depend on how the card is prepared.

1. **Format the card as FAT (FAT16/FAT32).**  
	On macOS you can do this with Disk Utility.
2. **Do not create folders.**  
	Put all audio files in the root of the card.
3. **Copy files in the desired order.**  
	The first file you copy becomes file `1`, the second becomes file `2`, and so on.
4. **Remove hidden macOS files.**  
	macOS tends to create `.DS_Store`, `.Trashes` and `._*` files. After copying audio files, open a terminal and run (replace `AUDIO` with your card’s name):

	```bash
	cd /Volumes/AUDIO/
	rm -rf .DS_Store .Trashes ._*
	```

5. Safely eject the card, insert it into the DFPlayer, and reboot the device.

This process ensures that DFPlayer numbering matches what the firmware expects.

---

## Power / supply

Quick reminder of the main rails:

| Rail / pin   | Connected to            | Voltage | Notes                         |
|--------------|-------------------------|--------:|-------------------------------|
| 5 V (Vin)    | DFPlayer VCC, relay VCC |   5 V   | Prefer a stable external rail |
| 3.3 V (MCU)  | ESP8266 Vcc, OLED Vcc   |   3.3 V | From regulator                |
| GND          | Common ground           |   0 V   | Tie all grounds together      |

See `WIRING.md` for the full wiring and decoupling suggestions.

---

## Misc notes / ideas

- If audio is noisy, check the 5 V rail and the ground layout and add extra bulk capacitance near the DFPlayer.
- If JSON downloads seem flaky, watch the ESPHome logs for the `prayer`, `tz`, or `update` tags while reproducing the problem.


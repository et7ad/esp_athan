**Bill Of Materials (placeholder)**

This file is a placeholder for the full Bill Of Materials. I will populate it with exact part numbers, quantities, and suggested vendors shortly. For now, the important references are:

- KiCad project: `athanV1_PCB/` (schematic, board, footprints)
- DFPlayer Mini module (UART, microSD audio playback)
- ESP8266 module / D1 Mini (ESP-12F/ESP-12E style board)
- SSD1306 128x64 I2C OLED display (0.96" or similar)
- Buttons (2) for `ui_next` and `ui_select`
- Relay (if using external relay on `GPIO13`) and transistor/driver as needed
- Power supply (5V for DFPlayer + ESP; check your board power requirements)
- MicroSD card for DFPlayer (with audio files numbered for DFPlayer)

Please do not build from this list yet — I'll update this file with exact references, footprints, and quantities (including links to DigiKey/Mouser/Aliexpress) in a follow-up commit.

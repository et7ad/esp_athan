## Wiring Summary

This document summarizes the hardware connections implied by `athan.yaml` for the ESP8266 (`d1_mini` board). It lists every ESP pin as `D# (GPIO#)` where applicable, shows how power should be arranged (ESP from a 3.3V regulator; input power provided directly to modules), recommends decoupling caps, and includes a simple wiring table.

### Assumptions and notes
- **Board:** Wemos/D1 Mini (ESP8266) as configured by `esp8266.board: d1_mini`.
- **Power:** Input power (Vin) is the raw supply from your adapter (commonly 5V or higher). Per your request, Vin goes directly to modules that need it (DFPlayer, relay coils, etc.). The ESP8266 must be powered from a stable 3.3V regulator (do NOT feed Vin directly to the ESP 3.3V pin unless a regulated 3.3V supply is used).
- **Ground:** All grounds (ESP, DFPlayer, OLED module, relay, power supply) must be common.
- **Capacitors:** Add decoupling capacitors around the regulator and the modules:
  - Input (Vin) side: 100 µF electrolytic (or 47–220 µF) + 0.1 µF ceramic close to regulator input.
  - Regulator output (3.3V): 10 µF (or 22 µF) electrolytic + 0.1 µF ceramic close to ESP Vcc.
  - Near DFPlayer: at least 100 µF electrolytic (DFPlayer can draw spikes on playback).

### GPIO label map (Wemos D1 mini)
This shows the common D# ↔ GPIO# mapping for the `d1_mini` that is used in `athan.yaml`.

- `D0 (GPIO16)`
- `D1 (GPIO5)`
- `D2 (GPIO4)`
- `D3 (GPIO0)`
- `D4 (GPIO2)`
- `D5 (GPIO14)`
- `D6 (GPIO12)`
- `D7 (GPIO13)`
- `D8 (GPIO15)`
- `TX (GPIO1)` — serial TX0
- `RX (GPIO3)` — serial RX0

When this document lists a pin such as `D5 (GPIO14)`, it means the board pin labelled `D5` which is `GPIO14` on the ESP8266.

### Power rails (recommended wiring)

- `Vin` (input power from adapter): e.g., 5V (or 5–12V depending on your modules). Connect `Vin` to the 5V devices that require it (DFPlayer Vcc, relay Vcc if using a relay module), and to the input of the 3.3V regulator.
- `3.3V` (regulator output): connect to the ESP8266 `3V3` pin and to 3.3V devices like an SSD1306 module when it is a 3.3V version.
- `GND`: common ground to all modules and the regulator.

Recommended quick parts list for power stability:
- Voltage regulator: e.g., an AMS1117-3.3, or a switching buck regulator capable of supplying ~500–1000 mA for ESP + DFPlayer and other loads.
- Caps: Input 100 µF + 0.1 µF, Output 10 µF + 0.1 µF. DFPlayer: 100 µF at its Vcc.

### Connections table (signals extracted from `athan.yaml`)

| Component | ESP pin | ESP pin (GPIO#) | Wire To (module pin) | Notes |
|---|---:|---:|---|---|
| I2C SDA (SSD1306 SDA) | `D2` | `GPIO4` | `SSD1306 SDA` | I2C data line (pull-ups on module or board). SSD1306 `Vcc` should be 3.3V. |
| I2C SCL (SSD1306 SCL) | `D1` | `GPIO5` | `SSD1306 SCL` | I2C clock line. Address used in config: `0x3D`. |
| SSD1306 RESET | `D0` | `GPIO16` | `SSD1306 RST` | Reset pin wired to `D0 (GPIO16)` as `reset_pin: D0` in YAML. |
| DFPlayer RX (module RX) <= MCU TX | `TX` | `GPIO1` | `DFPlayer RX` | UART TX from MCU connects to DFPlayer RX. In `athan.yaml`: `uart.tx_pin: GPIO1` (i.e. TX). |
| DFPlayer TX (module TX) => MCU RX | `RX` | `GPIO3` | `DFPlayer TX` | UART RX from module to MCU RX. In `athan.yaml`: `uart.rx_pin: GPIO3`. |
| ui_next (button) | `D5` | `GPIO14` | `Button` -> `GND` (button to ground) | Configured as `INPUT_PULLUP` and `inverted: true` in YAML. Connect one side of the button to `D5`, the other to GND. |
| ui_select (button) | `D6` | `GPIO12` | `Button` -> `GND` | Also `INPUT_PULLUP` + `inverted: true`. |
| Built-in LED (output) | `D4` | `GPIO2` | `LED` (via `led_output`) | `output:` uses `GPIO2` and `inverted: true` in `light` entry; that maps to the built-in LED on many boards. |
| External relay control | `D7` | `GPIO13` | `Relay module IN` | Relay Vcc -> Vin (5V) (module dependent), GND common. If using a bare relay coil, use a transistor/driver and diode; if module, ensure its Vcc matches Vin. |
| DFPlayer / Audio control | (no extra pin) | | `dfplayer` component uses UART pins above | DFPlayer playback files are triggered from the firmware. DFPlayer requires 5V Vcc typically — feed from Vin (not 3.3V). |

### Power wiring table

| Rail | Source | Destinations | Notes |
|---|---|---|---|
| `Vin` (raw input, often 5V) | Adapter / battery | `DFPlayer Vcc`, `Relay Vcc` (module), other 5V modules | Provide common ground. |
| `3.3V` (regulated) | 3.3V regulator output | `ESP8266 3V3`, `SSD1306 Vcc` (if 3.3V version) | Use recommended caps near regulator and ESP. |

### Button wiring detail

- Both `ui_next` and `ui_select` are configured with `mode: INPUT_PULLUP` and `inverted: true` in `athan.yaml`. That means:
  - Wire one side of each button to the ESP pin (`D5` or `D6`).
  - Wire the other side to `GND`.
  - The firmware uses the internal pull-up; pressing the button pulls the pin low.

### DFPlayer notes
- DFPlayer Mini typically requires 5V on `Vcc` and draws current during playback. Provide a solid 5V supply (Vin) and a 100 µF electrolytic near the DFPlayer power pins.
- UART wiring: MCU `TX` (GPIO1) -> DFPlayer `RX`; MCU `RX` (GPIO3) <- DFPlayer `TX`.

### Relay notes
- If using a relay module with an onboard driver, you can power its Vcc from `Vin` and drive its input from `D7 (GPIO13)`. Ensure the relay module's input logic matches the ESP logic or use a transistor level-shifter/driver. For a bare relay coil, use a transistor + diode + external supply sized for the coil.

### Recommended decoupling placements (quick)
- Place 100 µF electrolytic at Vin near the board entry point.
- Place 100 µF electrolytic close to DFPlayer Vcc and a 0.1 µF ceramic nearby.
- Place 10 µF + 0.1 µF at the regulator output (3.3V) close to the regulator.
- Place a 0.1 µF ceramic right across the ESP 3V3 and GND pins.

### Final checklist before powering up
- Verify common ground between Vin, regulator ground, DFPlayer, relay, and ESP.
- Verify the regulator is a stable 3.3V supply capable of the total expected current (ESP8266 + any WiFi peaks + peripherals).
- Confirm DFPlayer & relay Vcc ratings and connect them to Vin (not to the 3.3V regulator) if they require 5V.
- Add caps as recommended.

This file is derived from the current `athan.yaml` pin assignments. If you change pins in the YAML, please remember to update this wiring summary to match.

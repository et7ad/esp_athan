# ESP Athan TODO

## Next Versionxw

### DFPlayer stuck recovery via hardware power cycling

- **Hardware change**: Wire DFPlayer VCC through an N-channel MOSFET (or NPN transistor) controlled by a free ESP GPIO pin, so the ESP can cut and restore power to the DFPlayer programmatically
- **Firmware change**: Add a watchdog that monitors playback duration — track when the last play command was sent and what the expected duration is (short UI click vs long athan). If the DFPlayer has been "playing" far longer than expected (e.g. a 1-second click still active after 10 seconds, or an athan still active after 6 minutes), trigger a power cycle: cut VCC via the MOSFET, wait ~500ms, restore VCC, wait ~3s for the clone to reinitialize, then restore volume and clear the athan_playing flag
- **Why**: Cheap MH2024K DFPlayer clones can lock up with the DAC/amplifier stuck on (LED stays on, no audio). The serial reset command (0x0C) does NOT recover a locked clone — only a full power cycle guarantees recovery

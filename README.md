# Rogue End Run

An independent **Arduboy** end-run adaptation inspired by **Rogue 5.4.4**. This is **not** a full Rogue port. The game will start on Level 26, recover the Amulet of Yendor, skip directly to a playable Level 1, and win only after exiting to the surface with the Amulet.

**Current stage:** Milestone 0 hardware/title-screen foundation. No dungeon, combat, or winning sequence is implemented yet.

## Build

Requires Arduino CLI, the official Arduino AVR core, and the **Arduboy2** library. On macOS/Linux:

```sh
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli lib install Arduboy2
arduino-cli compile --fqbn arduino:avr:leonardo --output-dir build RogueEndRun
```

The Leonardo target shares the ATmega32U4 with standard Arduboy hardware and is used for the **compile smoke test**. For flashing a real Arduboy, use the Arduboy-compatible board package and the correct board/port selection; do not assume a Leonardo-formatted upload is hardware-validated.

To measure footprint, run `./scripts/build-and-size.sh` after installing the dependencies. Measurements must come from a real compile; see [hardware measurements](docs/hardware.md).

## Try the Milestone 0 title screen

Open `RogueEndRun/RogueEndRun.ino` in Arduino IDE or load a compiled HEX in an Arduboy-compatible emulator. D-pad Up/Down selects **New End Run**, **Controls**, or **About**; A opens Controls/About and B returns. New End Run is deliberately non-functional until gameplay milestones.

## Reference and license

Source-of-truth roadmap: [Rogue End Run roadmap](https://docs.google.com/document/d/1qtW7MGhyMydRdeI-r8U6DetnJazt-aTfJX8_HFpAq_c/edit).

- [Source audit and behavior mapping](docs/source-audit.md)
- [Hardware build/simulator checklist](docs/hardware.md)
- [Notices and attribution](NOTICE.md)
- [Rogue license terms](LICENSE.TXT)

**Rogue** by Michael Toy, Ken Arnold, and Glenn Wichman. This project is independent and is not endorsed by Rogue's authors or other contributors. Original Rogue source reference: https://github.com/Davidslv/rogue.

No persistent storage, scores, or graveyard integration is planned for the first release.

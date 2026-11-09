# Standard Arduboy hardware and smoke test

Target is Arduboy (ATmega32U4, 128x64 monochrome OLED). Arduboy2 is the rendering/input dependency; no FX storage required.

## Build on host

```sh
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli lib install Arduboy2
./scripts/build-and-size.sh
```

The script compiles `RogueEndRun/RogueEndRun.ino` for the Arduino Leonardo ATmega32U4 baseline, locates the produced ELF, and prints `avr-size` results. For release, also build/upload with an Arduboy-specific board definition, and verify its compiled hardware footprint.

## Simulator smoke test (pending)

- [ ] Build succeeds and a HEX/ELF is generated
- [ ] Load the HEX in a compatible Arduboy emulator
- [ ] Verify bright-on-dark 128x64 title and all three menu labels
- [ ] Up/Down selects exactly one item per *press* (no fast auto-repeat)
- [ ] A opens Controls and About, B returns to title
- [ ] Selecting New End Run has no action in Milestone 0
- [ ] Verify no display glitches and no unintended input repeat

## On-hardware smoke test (pending)

- [ ] Flash with an Arduboy-compatible tool/board setting
- [ ] Confirm screen, controls, and reliable return to title
- [ ] Note measured program and static data size from actual build

## Measurement log

| Build | Flash (program storage) | Static SRAM | Dynamic headroom | Evidence |
| --- | --- | --- | --- | --- |
| Initial Milestone 0 | Not measured | Not measured | Not measured | Toolchain not available in current authoring environment |

Do not substitute nominal ATmega32U4 limits for measured usage. Stack use and runtime dynamic headroom cannot be determined solely from `avr-size`.

#!/usr/bin/env sh
set -eu

command -v arduino-cli >/dev/null 2>&1 || { echo "Missing arduino-cli" >&2; exit 1; }
mkdir -p build
arduino-cli compile --fqbn arduino:avr:leonardo --output-dir build RogueEndRun
elf=$(find build -maxdepth 1 -type f -name '*.elf' -print -quit)
[ -n "$elf" ] || { echo "No ELF produced" >&2; exit 1; }
if command -v avr-size >/dev/null 2>&1; then
  avr-size -C --mcu=atmega32u4 "$elf"
else
  echo "Install avr-binutils/Arduino AVR toolchain to measure flash and SRAM."
  echo "Build output: $elf"
fi

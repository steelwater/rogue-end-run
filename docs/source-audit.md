# Rogue 5.4.4 source audit — Milestone 0

Reference repository: https://github.com/Davidslv/rogue. Audited files: `rogue.h`, `new_level.c`, `pack.c`, `command.c`, `rip.c`, `LICENSE.TXT`. The current project uses original Arduboy presentation code, not a direct C/curses port.

| Reference behavior | Evidence | End Run adaptation | Classification |
| --- | --- | --- | --- |
| Amulet eligibility starts at depth 26 | `rogue.h`: `AMULETLEVEL 26` | Start at playable Level 26 | Original threshold / adapted start |
| Amulet glyph is comma | `rogue.h`: `AMULET ','` | ASCII-derived Amulet marker | Source faithful |
| Stair glyph is percent | `rogue.h`: `STAIRS '%'` | Distinct stair/surface tile | Source faithful |
| Amulet placed on floor when depth >= 26 and not held | `new_level.c`: `put_things()` | Guarantee reachable Amulet in small map | Intentional guarantee |
| Amulet becomes owned through pickup | `pack.c`: `add_pack()` sets `amulet = TRUE` | A-on-tile picks up; explicit ownership flag | Input adaptation |
| Upward traversal requires Amulet | `command.c`: `u_level()` invoked via '<' | A activates climb only after pickup | Input adaptation |
| Ascending Level 1 to 0 triggers victory | `command.c` upward traversal and `rip.c`: `total_winner()` | Playable Level 1 must be exited with Amulet | Source faithful victory gate |
| Win includes victory banner, escape message, loot valuation and score | `rip.c`: `total_winner()` | Paginate original prose; compact valuation if practical | Display adaptation |
| Death ends game | `rip.c`: `death()` | End session, no automatic victory | Source faithful |
| Original screen is curses 80x24 and supports keyboard commands | `rogue.h` / `command.c` | 128x64 Arduboy2 and D-pad/A/B | Hardware adaptation |

## Explicit deviations

1. The initial character is an already experienced Rogue, not a level-one beginner.
2. After Amulet pickup, **A** skips Levels 25 through 2 as a narrative transition; those floors are neither generated nor simulated.
3. Level 1 is still playable and must be survived; merely collecting the Amulet is **not** victory.
4. Simplified tactical system/inventory and map sizes are expected to fit ATmega32U4 resources.
5. No EEPROM saves, high-score persistence, or Rogue Graveyard transfer in the first release.
6. No NetHack class, alignment, deity, or related systems.

## Acceptance boundary

Milestone 0 is complete **in code** when the title smoke test builds and displays on emulator and hardware, and measured flash/SRAM numbers are recorded. Those external tests and measurements are presently unverified. Gameplay begins in Milestone 1.

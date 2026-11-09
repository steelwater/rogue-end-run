/*
 * Rogue End Run — Milestone 0 hardware/title smoke test.
 * Original adaptation shell; no Rogue game code copied here.
 * Rogue attribution and license: ../LICENSE.TXT and ../NOTICE.md
 */
#include <Arduboy2.h>
Arduboy2 arduboy;

enum Scene : uint8_t { TITLE, CONTROLS, ABOUT };
Scene scene = TITLE;
uint8_t selected = 0;
constexpr uint8_t MENU_COUNT = 3;

void drawTitle() {
  arduboy.setTextSize(1);
  arduboy.setCursor(22, 2);
  arduboy.print(F("ROGUE END RUN"));
  arduboy.drawFastHLine(11, 15, 106, WHITE);
  arduboy.setCursor(28, 20); arduboy.print(F("Dungeon 26"));
  const __FlashStringHelper* labels[MENU_COUNT] = {
    F("New End Run"), F("Controls"), F("About")
  };
  for (uint8_t i = 0; i < MENU_COUNT; ++i) {
    arduboy.setCursor(12, 34 + 9 * i);
    arduboy.print(i == selected ? F(">") : F(" "));
    arduboy.print(labels[i]);
  }
}

void drawControls() {
  arduboy.setCursor(0, 0); arduboy.print(F("CONTROLS"));
  arduboy.setCursor(0, 13); arduboy.print(F("D-pad: select/move"));
  arduboy.setCursor(0, 25); arduboy.print(F("A: confirm/action"));
  arduboy.setCursor(0, 37); arduboy.print(F("B: back/inventory"));
  arduboy.setCursor(0, 55); arduboy.print(F("B: return"));
}

void drawAbout() {
  arduboy.setCursor(0, 0); arduboy.print(F("ROGUE END RUN"));
  arduboy.setCursor(0, 13); arduboy.print(F("Milestone 0 v0.0.1"));
  arduboy.setCursor(0, 25); arduboy.print(F("Rogue 5.4.4 inspired"));
  arduboy.setCursor(0, 37); arduboy.print(F("Toy / Arnold /"));
  arduboy.setCursor(0, 46); arduboy.print(F("Wichman"));
  arduboy.setCursor(0, 55); arduboy.print(F("B: return"));
}

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.initRandomSeed();
}

void loop() {
  if (!arduboy.nextFrame()) return;
  arduboy.pollButtons();
  if (scene == TITLE) {
    if (arduboy.justPressed(UP_BUTTON)) {
      selected = (selected + MENU_COUNT - 1) % MENU_COUNT;
    }
    if (arduboy.justPressed(DOWN_BUTTON)) {
      selected = (selected + 1) % MENU_COUNT;
    }
    if (arduboy.justPressed(A_BUTTON)) {
      if (selected == 1) scene = CONTROLS;
      else if (selected == 2) scene = ABOUT;
      // New End Run intentionally remains a title-screen placeholder in M0.
    }
  } else if (arduboy.justPressed(B_BUTTON)) {
    scene = TITLE;
  }
  arduboy.clear();
  switch (scene) {
    case TITLE: drawTitle(); break;
    case CONTROLS: drawControls(); break;
    case ABOUT: drawAbout(); break;
  }
  arduboy.display();
}

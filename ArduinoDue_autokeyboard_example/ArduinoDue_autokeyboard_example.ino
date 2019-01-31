#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  delay(10000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("notepad.exe");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("All your computer are belong to me");
}

void loop() {}

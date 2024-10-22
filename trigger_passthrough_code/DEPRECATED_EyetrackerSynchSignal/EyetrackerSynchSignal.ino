/*
Uses Arduion Due's keyboard emulation to pass a keyboard character trigger from one PC to another

To debug, turns on an LED for character 'J' received over serial (USB) via PC code or the IDE serial monitor
*/

//#include "Keyboard.h"

void setup() {

  
  // Start serial communication with the same baud rate as Unity
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // Example: Trigger LED on "J" received

  // initialize control over the keyboard:
//  Keyboard.begin();

}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    char receivedChar = Serial.read(); // Read the incoming data

    // If the received character is 'J', trigger an action
    if (receivedChar == 'J') {
      digitalWrite(LED_BUILTIN, HIGH);  // Example: Turn on an LED
      delay(500);                       // Delay for half a second
      digitalWrite(LED_BUILTIN, LOW);   // Turn off the LED

      delay(500); 
    //  Keyboard.write(receivedChar + 1);
      // Keyboard.begin();
      // delay(10000);
      // Keyboard.press(KEY_LEFT_GUI);
      // Keyboard.press('r');
      // delay(100);
      // Keyboard.releaseAll();
      // delay(500);
      // Keyboard.print("notepad.exe");
      // Keyboard.press(KEY_RETURN);
      // delay(100);
      // Keyboard.releaseAll();
      // delay(2000);
      // Keyboard.print("All your computer are belong to me");
    }
  }
}

//reciever - arduino DUE listens for digital pin trigger from sender arduino; upon receiving, it sends a trigger out as a keyboard to a connected PC

#include "Keyboard.h" //keyboard HID library for DUE to simulate keyboard outputs over USB

#define PIN 3 //define input pin on the DUE
int led = 13; //specify DUE onboard LED pin number ("13") for communication monitoring with sender
uint8_t prevState = LOW;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  // ~~~uncomment for debugging
  //Serial.println();
  //Serial.println("Configuring PIN for INPUT");
  // ~~~
  
  pinMode(PIN, INPUT);
  pinMode(led, OUTPUT);

// ~~~for debugging, open notepad and print character to it
//  Keyboard.begin();
//  delay(2000);
//  Keyboard.press(KEY_LEFT_GUI);
//  Keyboard.press('r');
//  delay(100);
//  Keyboard.releaseAll();
//  delay(500);
//  Keyboard.print("notepad.exe");
//  Keyboard.press(KEY_RETURN);
//  delay(100);
//  Keyboard.releaseAll();
  //delay(2000);
// ~~~

}

void loop() {
  uint8_t state = digitalRead(PIN);
  if (prevState != state) {
    prevState = state;
    //Serial.print("PIN status: ");
    if (state == HIGH) {
      Serial.println("HIGH"); //print digital input trigger status to serial to indicate communication was received
      digitalWrite(led, HIGH); //flash LED on to indicate communication was received
      Keyboard.print("t");
    } else {
      Serial.println("LOW"); //print digital input trigger status to serial to indicate communication was received
      digitalWrite(led, LOW); //flash LED off to indicate communication was received
    }
  }
  delay(25);
}

// int led = 13; 
// int incomingByte;     

// void setup() {
 
//   Serial.begin(9600);
  
//   pinMode(3,INPUT)

//   pinMode(led, OUTPUT);
// }

// void loop() {
  
//   if (Serial.available() > 0) {  
//     incomingByte = Serial.read(); 
//     if (incomingByte == 'H') {
//       digitalWrite(led, HIGH);
//     }
//     if (incomingByte == 'L') {
//       digitalWrite(led, LOW);
//     }
//   }
// }
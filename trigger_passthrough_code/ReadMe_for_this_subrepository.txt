sender Arduino is assumed to be a basic Arduino Uno. Its code listens for a "J" trigger from a computer over USB, then sends a digital trigger signal out

receiver Arduino is assumed to be an Arduino DUE or similar, which has USB HID emulation capability. It listens for the digital trigger signal from the sender Arduino, and then masquerades as a keyboard, sending out a character to another computer over USB


(designed use case: Unity navigation task sends a trigger to another computer when a VR event occurs; in this case, the Unity task on one PC can put triggers/timestamps in an E-Prime machine logging eye-tracker data)

You can test it works by connecting the "sender" Arduino to a computer with the Arduino IDE installed and the correct packages for the board you are using installed (e.g., Adafruit metro (Uno Clone) for Liz's study) and the sender Arduino to another computer with a notepad open on it. Then, open the serial monitor in Arduino IDE on the sender computer, type "J" (no quotations) in the command line of the serial monitor and hit "enter" - you should see a "t" get printed in the notepad on the receiver computer. 
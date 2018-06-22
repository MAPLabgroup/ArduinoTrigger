// sends a shock trigger via serial (USB) output. This version runs with voltage to the trigger pin OFF, and then sends a pulse. STM100C might work better the other way around, triggering the pulse when voltage is removed

char incomingByte;

void setup() {
  // initialize serial 
  Serial.begin(57600);
  pinMode(10,OUTPUT);
}

void loop() {
  digitalWrite(10, LOW);
  
  if (Serial.available() ) {

    incomingByte = Serial.read(); // read the incoming byte:
    //incomingByte = Serial.parseInt();
    
    // say what you got:
    //    Serial.print("\nI received: ");
    //    Serial.println(incomingByte);

    if (incomingByte == 's')
    {
      pulseOut();
    }
    Serial.flush(); //flushes the buffer of incoming serial data
  }
}
void pulseOut() {
  digitalWrite(10, HIGH);
  delay(100); // duration of light in msec
  digitalWrite(10,LOW);
  //delay(1000);
}
 


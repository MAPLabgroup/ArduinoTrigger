// sends a shock trigger via serial (USB) output. This version runs with voltage to the trigger pin ON, and then triggers by transiently shutting pin off.

char incomingByte;

void setup() {
  // initialize serial 
  Serial.begin(57600);
  pinMode(10,OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);
  
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
  digitalWrite(10, LOW);
  delay(100); // duration of light in msec
  digitalWrite(10,HIGH);
  //delay(1000);
}
 


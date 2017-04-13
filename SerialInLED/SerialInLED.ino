int LED8[] = {5,6,7,8,9,10,11,12};
void setup() {
  // put your setup code here, to run once:
  for(int i = 0 ; i < 8 ; i++) {
    pinMode(LED8[i], OUTPUT);
    digitalWrite(LED8[i],LOW);
  }

  Serial.begin(9600);

}

int ledon = 0;
void loop() {

  if( Serial.available()) {
  
      char in = Serial.read();
      ledon = in - '0';
    
      int ledState = digitalRead(LED8[ledon]);
      digitalWrite(LED8[ledon],!ledState);
  
  }
}

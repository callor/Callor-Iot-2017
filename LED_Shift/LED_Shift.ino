byte leds[8] ;
void setup() {

  int ledStart = 2;
  for(int i = 0 ; i < 8 ; i++){
    leds[i] = ledStart ++;
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);

}

int ledVal = 1;
int keyin = 0;

void loop() {

  if(Serial.available()){
    keyin = Serial.read();
    ledVal = keyin - '0'; 
  }
  Serial.println("---------------------");
  for(int i = 0 ; i < 8;i++){
    int bit = bitRead(ledVal,i);
    digitalWrite(leds[i],bit);
  }
  Serial.print("input:");
  Serial.print(keyin - '0');
  Serial.print("\t");

  Serial.print("shift:");
  Serial.println(ledVal);

  // ledVal 을 shift-left
  ledVal = ledVal << 1 ;
  if(ledVal > 256) ledVal = keyin - '0' ;
  delay(1000);

}





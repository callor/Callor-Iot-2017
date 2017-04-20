/*
   2017-04-18
   프로젝트 : LED 2 BIN
     LED 8개를 이용해서 2진수를 나타낸다.



*/

#define LED_0 2
#define LED_1 3
#define LED_2 4
#define LED_3 5
#define LED_4 6
#define LED_5 7
#define LED_6 8
#define LED_7 9

int leds[] = { LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, } ;

void setup() {
  for ( int i = LED_0 ; i <= LED_7 ; i++ ) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

}

int count = 0 ;
void loop() {

  for (int i = 0 ; i < 8 ; i++) {
    int bit = bitRead(count, i) ;
    digitalWrite(leds[i], bit);
    
  }
  delay(1000);

  Serial.println(count++);


}









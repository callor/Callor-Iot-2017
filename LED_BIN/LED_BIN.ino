/**
 * LED 8개를 이용한 이진수 표현
 */

byte leds[8] ;
void setup() {

  int ledStart = 2;
  for(int i = 0 ; i < 8 ; i++) {
    leds[i] = ledStart ++ ;
    pinMode(leds[i] , OUTPUT);
  }
  Serial.begin(9600);
}

int keyin = 0;
int data = 0;
void loop() {

  if(Serial.available()) {
     keyin = Serial.read(); // 0(48) ASCII 입력
     data = keyin - '0'; // ASCII 코드를 실제 숫자값으로 바꾸기
     Serial.println("----------------------");
  }
  for(int i = 0 ; i < 8 ; i++) {
    int bit = bitRead(data,i);
    digitalWrite(leds[i],bit);
  }

}






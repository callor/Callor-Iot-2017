#include <LiquidCrystal.h>

LiquidCrystal myLCD(7,8,9,10,11,12);

void setup() {
  myLCD.begin(16,2); // 16x2 LCD 사용하겠다.
  myLCD.clear(); // LCD 화면 Clear
//  myLCD.print("Hello World");
  Serial.begin(9600);
}

int count = 0;
void loop() {

  myLCD.clear();
  int light = analogRead(A5); // 빛의 양에 0부터 1023의 값을 얻을수 있다.

  myLCD.setCursor(0,0);
  myLCD.print("Current Light");

  myLCD.setCursor(0,1);
  myLCD.print(light);

  delay(1000);

}

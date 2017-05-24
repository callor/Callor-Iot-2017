#include <LiquidCrystal.h>

LiquidCrystal myLCD(7,8,9,10,11,12);

void setup() {
  myLCD.begin(16,2); // 16x2 LCD 사용하겠다.
  myLCD.clear(); // LCD 화면 Clear
//  myLCD.print("Hello World");
}

void loop() {

  myLCD.setCursor(0,0); // 첫줄 첫칸에 커서를 위치 하겠다.
  myLCD.print("Hello Word");

  myLCD.setCursor(0,1) ; // 둘째줄 첫칸에 커서를 위치한다.
  myLCD.setCursor(5,1) ; // 둘째줄 6번째 칸에 커서를 위치
  myLCD.print("Korea");

}

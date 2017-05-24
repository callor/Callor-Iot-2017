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
  // 시리얼 모니터에 입력된 문자를 문자열로 변환
  String s = "";
  if(Serial.available()){
    while(Serial.available()){
      char c = Serial.read(); // char
      s += c; // 입력된 알파벳을 문자열로 만들기
    }
  }

  myLCD.setCursor(0,0); // 첫줄 첫칸에 커서를 위치 하겠다.
  myLCD.print("Hello Word");

  myLCD.setCursor(0,1) ; // 둘째줄 첫칸에 커서를 위치한다.
//  myLCD.setCursor(5,1) ; // 둘째줄 6번째 칸에 커서를 위치
//  myLCD.print("Korea");
  delay(1000);
  myLCD.print(count++);
  
  myLCD.setCursor(5,1);
  myLCD.print(s); // 문자열을 표시

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

// A0 부터 A1 아날로그 입력
// 전압의 변화량을 읽는 포트
void loop() {
  // put your main code here, to run repeatedly:

  int aRead = analogRead(A1);

  Serial.println(aRead);

}

void setup() {
  // put your setup code here, to run once:
  
  pinMode(11,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

//  digitalWrite(11,HIGH); // 스위치 ON
//  delay(1000);  // 상태 유지, ms : 1000 = 1초
//
//  digitalWrite(11,LOW);  // 스위치 OFF
//  delay(1000); 

  for(int i = 0 ; i< 255;i++){
    analogWrite(11,i);
    delay(100);
  }

  for(int i = 255; i>0 ; i--) {
    analogWrite(11,i);
    delay(100);
  }

}

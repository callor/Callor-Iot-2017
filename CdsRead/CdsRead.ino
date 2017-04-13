void setup() {

  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

// Max : 어두울때 최대값
// Nin : 밝을때 최소값

int aMax = 1023;
int aMin = 0;
void loop() {


  // int aAvg = 990;
  int aIn = analogRead(A1);
  if(aMax < aIn) aMax = aIn; // 최대값 자동으로 찾기
  if(aMin > aIn) aMin = aIn; // 최소값 자동으로 찾기

  int aMax1 = 0;
  int aMin1 = 0;
  int value = map(aIn,aMin,aMax,0,120);

  digitalWrite(3,LOW);
  if(value > 60){
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
  }

//  analogWrite(3,value);
  Serial.println(value);
//  delay(500);

}

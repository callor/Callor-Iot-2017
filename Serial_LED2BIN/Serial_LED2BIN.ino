
#define LED_0 2
#define LED_1 3
#define LED_2 4
#define LED_3 5
#define LED_4 6
#define LED_5 7
#define LED_6 8
#define LED_7 9

int leds[] = {LED_0,LED_1,LED_2,LED_3,LED_4,LED_5,LED_6,LED_7 };

void setup() {
  for(int i = LED_0 ; i <= LED_7 ; i ++ ) {
    pinMode(i , OUTPUT);
  }

  Serial.begin(9600);
  
}

int count = 0 ;
int intNum1 = 0 ;
int intNum2 = 0 ;

void loop() {

//  int Serial.read();
  
  if(Serial.available()){
    int num = Serial.read() - '0' ; // 숫자로 변환
    if(intNum1 != 0) {
      intNum2 = num ;
    } else {
      intnum1 = num ;
    }
  }

  if(intNum1 != 0 && intNum2 != 0) {
    int intSum = intNum1 + intNum2 ;
    for(int i = 0 ; i < 8 ;i++) {
      int b = bitRead(intSum,i);
      digitalWrite(leds[i],b);
    }
    intNum1 =0;
    intNum2 =0;
  }
  
  
//  for(int i = 0 ; i < 8 ;i++) {
//    int b = bitRead(count,i);
//    digitalWrite(leds[i],b);
//  }
//  delay(1000);
//  count ++ ;
}





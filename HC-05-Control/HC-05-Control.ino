#include <SoftwareSerial.h>

#define blTX 2
#define blRX 3

#define AIRCON 5
#define BOILER 6
#define LIGHT1 7

SoftwareSerial blPort(blTX,blRX);

void setup() {

  Serial.begin(9600);
  blPort.begin(38400);
  pinMode(AIRCON,OUTPUT);
  pinMode(BOILER,OUTPUT);
  pinMode(LIGHT1,OUTPUT);

}

void loop() {
  // 블루투스가 우리에게 전송을 하였는가?
  if(blPort.available()) {
    char c = blPort.read();
    if(c=='A') {
      digitalWrite(AIRCON, !digitalRead(AIRCON));
      Serial.println("Air Con");
    }
    if(c=='B') {
      Serial.println("Boiler");
    }
    if(c=='1') {
      Serial.println("Light 1");
    }
//    Serial.write(blPort.read());
  }
  // 우리가 시리얼모니터를 통해서 전송을 하려고 하는가?
  if(Serial.available()) {
    blPort.write(Serial.read());
  }



}

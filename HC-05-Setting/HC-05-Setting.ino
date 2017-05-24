#include <SoftwareSerial.h>

#define blTX 2
#define blRX 3

SoftwareSerial blPort(blTX,blRX);

void setup() {

  Serial.begin(9600);
  blPort.begin(38400);

}

void loop() {
  // 블루투스가 우리에게 전송을 하였는가?
  if(blPort.available()) {
    Serial.write(blPort.read());
  }
  // 우리가 시리얼모니터를 통해서 전송을 하려고 하는가?
  if(Serial.available()) {
    blPort.write(Serial.read());
  }
}





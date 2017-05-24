#include <MyLib.h>

MyLib myLib(13);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  myLib.ledOn();
  delay(1000);
  myLib.ledOff();
  delay(1000);

}

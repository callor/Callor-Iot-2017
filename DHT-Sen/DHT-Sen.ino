#include <DHT.h>

#define DHT_PIN 13 // 센서 시그널 핀
#define DHT_TYPE DHT22 // 센서 타입(AM2302)
// DHT11
// DHT21 ( AM2301)

DHT dht(DHT_PIN, DHT_TYPE); // 객체 생성

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT-22 Test!!");

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(2000); // 오래된 센서와 호환을 위해서
  float hum = dht.readHumidity(); // 습도 읽기
  float temp = dht.readTemperature(); // 온도(섭씨 온도)
  float ftemp = dht.readTemperature(true) ; // 화씨로 읽기

  // 열 지수
  float heatIndex = dht.computeHeatIndex(temp,hum,false);

  // 센서로 부터 읽은값이 정상적인 실수 값이 아니면 다음으로 진행하지 않도록
  if(isnan(hum) || isnan(temp) || isnan(ftemp)) {
    Serial.println("Read Error");
    return ;
  }

  Serial.print("Humidity:");
  Serial.println(hum);
  Serial.println();

  // 섭씨 표시
  Serial.print("Temp(C):");
  Serial.print(temp);
  Serial.println("*C");
  Serial.println();

  Serial.print("Temp(F):");
  Serial.print(ftemp);
  Serial.println("*F");
  Serial.println();

  Serial.print("Heat Index:");
  Serial.print(heatIndex);
  

}

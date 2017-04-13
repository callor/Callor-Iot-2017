
#define SWPIN 7
#define LED 5

void setup() {
  // put your setup code here, to run once:

  pinMode(SWPIN,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(SWPIN) == HIGH){
     digitalWrite(LED,HIGH);
     delay(100);
     digitalWrite(LED,LOW);
     delay(100);
     Serial.println("OK");
  } else {
    digitalWrite(LED,LOW);
    Serial.println("NO");
  }
}

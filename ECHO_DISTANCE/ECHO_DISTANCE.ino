#define TRIGER 4
#define ECHO 3

void setup() {

  pinMode(ECHO,INPUT);
  pinMode(TRIGER,OUTPUT);

  Serial.begin(9600);


}

void loop() {
  float duration, distance;

  digitalWrite(TRIGER,HIGH);
  delay(10);
  digitalWrite(TRIGER,LOW);

  duration = pulseIn(ECHO,HIGH);

  distance = (float)((duration * 340)/10000) / 2;

  Serial.print(distance);
  Serial.println("cm");

  if(distance < 20) {
    tone(5,520,300);
  }
  delay(500);

  
  
}





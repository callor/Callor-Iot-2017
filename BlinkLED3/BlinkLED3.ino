
int LED3[] = {5,6,7,8,9,10,11,12};
  int count = 0;
void setup() {

  for(int i = 0; i < 8 ; i++) {
      pinMode(LED3[i],OUTPUT);
  }
}

int sw = LOW;
void loop() {
  
    count ++;
    digitalWrite(LED3[count%8], sw);
    delay(300);

    if(count % 8 == 0) sw ^= 1;

}

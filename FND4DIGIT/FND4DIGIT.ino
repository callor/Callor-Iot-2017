// 글자 표시 핀번호
// 아두이노 핀
// FND 핀
#define SEG_A 2 // 11
#define SEG_B 3 // 7
#define SEG_C 4 // 4
#define SEG_D 5 // 2
#define SEG_E 6 // 1
#define SEG_F 7 // 10
#define SEG_G 8 // 5

#define FND_01 9    // 6 1의자리
#define FND_02 10   // 8 10의 자리
#define FND_03 11   // 9 100의 자리
#define FND_04 12   // 12 1000 의 자리


byte numbers[] = {
  B0111111,  // 0 MSB   --  LSB
  B0000110,
  B1011011,
  B1001111,
  B1100110,
  B1101101,
  B1111101,
  B0000111,
  B1111111,
  B1101111  // 9
};

int FND[] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G} ;
int POS[] = {FND_01, FND_02, FND_03, FND_04} ;


void setup() {
  // put your setup code here, to run once:
  for (int i = 0 ; i < 7 ; i++) {
    pinMode(FND[i] , OUTPUT) ; // 값을 표현할  port를 출력으로
  }
  for (int i = 0 ; i < 4 ; i++) {
    pinMode(POS[i] , OUTPUT) ;
    digitalWrite(POS[i], LOW);
  }
}

int intCnt = 0 ;
void loop() {

  unsigned long start = millis() ; // 현재시간
  for (unsigned long i = 0 ; i < 1000; i = millis() - start ) {
    disp();
  }
  intCnt++;
}
void disp() {
  int dPos[] = {
    (intCnt) % 10,
    (intCnt / 10) % 10,
    (intCnt / 100) % 10,
    (intCnt / 1000) % 10
  };
  for (int i = 0 ; i < 4 ; i++) {
    digitalWrite(POS[i], LOW);
    segDisp(numbers[dPos[i]]);
    delay(5);
    digitalWrite(POS[i], HIGH);
  }
}

void segDisp(byte number) {
  for (int i = 0; i < 7 ; i++) {
    int bit = bitRead(number, i) ; // number에서 1비트씩 분리
    digitalWrite(FND[i], bit);
  }
}




/*
 * 2017-04-15
 * 프로젝트 : FND_01
 * FND 동작 실험 1
 *    FND에 숫자 0부터 9까지
 *    1초 간격으로 표시
 */

#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8

#define PIEZO 11

int segs[] = { SEG_A,SEG_B,SEG_C,SEG_D,SEG_E,SEG_F,SEG_G } ;

 /*
 * 0 : ABCDEF- : 1111110  
 * 1 : -BC---- : 0110000
 * 2 : AB-DE-G : 1101101
 * 3 : ABCD--G : 1111001
 * 4 : -BC--FG : 0110011
 * 5 : A-CD-FG : 1011011
 * 6 : A-CDEFG : 1011111
 * 7 : ABC---- : 1110000
 * 8 : ABCDEFG : 1111111
 * 9 : ABCD-FG : 1111011
 */
byte numbers[] = {
    B0111111,  // MSB   --  LSB
    B0000110,
    B1011011,
    B1001111,
    B1100110,
    B1101101,
    B1111101,
    B0000111,
    B1111111,
    B1101111
};
void setup() {
  for( int i = SEG_A ; i <= SEG_G ; i++ ) {
      pinMode(i,OUTPUT);
  }
}

void loop() {

    // 1초마다 숫자 카운트업
    for(int j = 0 ; j < 9 ; j ++ ) {
        for(int i = 0 ; i < 7 ;i++){
          int bit = bitRead(numbers[j],i) ;
          digitalWrite(segs[i],bit);
        }
    }
    delay(1000);

    
    
}









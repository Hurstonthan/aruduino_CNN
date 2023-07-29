#include <cvzone.h>
#define DELAY_MS 1

SerialData serialData(1, 1);
int array[1];
int check;
int valsRec;

const int shcpPin = 12;
const int stcpPin = 10;
const int dataPin = 11;

const int col1Pin = 9;
const int col2Pin = 8;
const int col3Pin = 7;
const int col4Pin = 6;
const int col5Pin = 5;
const int col6Pin = 4;
const int col7Pin = 3;
const int col8Pin = 1;

unsigned char matrixHex[] [8] = {
  {0x00, 0x7C, 0x82, 0x82, 0x82, 0x7C, 0x00, 0x00},
  {0x00, 0x00, 0x84, 0xFE, 0x80, 0x00, 0x00,0x00},
  {0x00, 0x84, 0xC2, 0xA2, 0x92, 0x8C, 0x00,0x00},
  {0x00, 0x42, 0x92, 0x9A, 0x96, 0x62, 0x00, 0x00},
  {0x00, 0x30, 0x2C, 0x20, 0xFE, 0x20, 0x00,0x00},
  {0x00, 0x5E, 0x92, 0x92, 0x92, 0x62, 0x00,0x00},
  {0x00, 0x7C, 0x92, 0x92, 0x92, 0x64, 0x00,0x00},
  {0x00, 0x02, 0x02, 0xE2, 0x1A, 0x06, 0x00,0x00},
  {0x00, 0x6C, 0x92, 0x92, 0x92, 0x6C, 0x00,0x00},
  {0x00, 0x4C, 0x92, 0x92, 0x92, 0x7C, 0x00,0x00},
};

int num = 0;
unsigned long prevMillis = 0;

void setup() {
  serialData.begin();
  pinMode(shcpPin, OUTPUT);
  pinMode(stcpPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(col1Pin, OUTPUT);
  pinMode(col2Pin, OUTPUT);
  pinMode(col3Pin, OUTPUT);
  pinMode(col4Pin, OUTPUT);
  pinMode(col5Pin, OUTPUT);
  pinMode(col6Pin, OUTPUT);
  pinMode(col7Pin, OUTPUT);
  pinMode(col8Pin, OUTPUT);

  pinMode(13,OUTPUT);
}

void loop() {

  serialData.Get(array);

  valsRec = array[0];
/*
  if (check != 2) {
    check = 1;
  }
  */
  
  if (millis() - prevMillis >= 1000) {
    prevMillis = millis();
    if (++num > 9) num = 0;
    //num = 2;
  }
 // printf("Here is the value %d\n", valsRec[0]);

 switch (valsRec) {

   case (0):
    call_num(valsRec);
    break;
   case (1):
   call_num(valsRec);
   break;
   case (2):
   call_num(valsRec);
   break;
   case (3):
   call_num(valsRec);
   break;
   case (4):
   call_num(valsRec);
   break;
   case (5):
   call_num(valsRec);
   break;
   case (6):
   call_num(valsRec);
   break;
   case (7):
   call_num(valsRec);
   break;
   case (8):
   call_num(valsRec);
   break;
   case (9):
   call_num(valsRec);
   break;
 }



 /*
//0

  HC595_shiftOut(matrixHex[check][0]);

  MATRIX_setCol(0,1,1,1,1,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

  
//1
  HC595_shiftOut(matrixHex[check][1]);

  MATRIX_setCol(1,0,1,1,1,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);
  
//2

  HC595_shiftOut(matrixHex[check][2]);

  MATRIX_setCol(1,1,0,1,1,1,1,1);

  delay(DELAY_MS);
  MATRIX_setCol (1,1,1,1,1,1,1,1);
  

//3
  HC595_shiftOut(matrixHex[check][3]);

  MATRIX_setCol(1,1,1,0,1,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

//4
  HC595_shiftOut(matrixHex[check][4]);

  MATRIX_setCol(1,1,1,1,0,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

//5

  HC595_shiftOut(matrixHex[check][5]);

  MATRIX_setCol(1,1,1,1,1,0,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

//6

  HC595_shiftOut(matrixHex[check][6]);

  MATRIX_setCol(1,1,1,1,1,1,0,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

  HC595_shiftOut(matrixHex[check][7]);

  MATRIX_setCol(1,1,1,1,1,1,1,0);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

*/
  
}

void call_num(int check) {
  //0

  HC595_shiftOut(matrixHex[check][0]);

  MATRIX_setCol(0,1,1,1,1,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

  
//1
  HC595_shiftOut(matrixHex[check][1]);

  MATRIX_setCol(1,0,1,1,1,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);
  
//2

  HC595_shiftOut(matrixHex[check][2]);

  MATRIX_setCol(1,1,0,1,1,1,1,1);

  delay(DELAY_MS);
  MATRIX_setCol (1,1,1,1,1,1,1,1);
  

//3
  HC595_shiftOut(matrixHex[check][3]);

  MATRIX_setCol(1,1,1,0,1,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

//4
  HC595_shiftOut(matrixHex[check][4]);

  MATRIX_setCol(1,1,1,1,0,1,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

//5

  HC595_shiftOut(matrixHex[check][5]);

  MATRIX_setCol(1,1,1,1,1,0,1,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

//6

  HC595_shiftOut(matrixHex[check][6]);

  MATRIX_setCol(1,1,1,1,1,1,0,1);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);

  HC595_shiftOut(matrixHex[check][7]);

  MATRIX_setCol(1,1,1,1,1,1,1,0);

  delay(DELAY_MS);

  MATRIX_setCol (1,1,1,1,1,1,1,1);
  

}

void HC595_shiftOut(unsigned char b) {
  digitalWrite(shcpPin,LOW);
  digitalWrite(stcpPin,LOW);

  for (int i = 0; i < 8; i++) {
    if (b & (0x80 >> i)) {
      digitalWrite(dataPin, HIGH);
    }
    else {
      digitalWrite(dataPin, LOW);
    }

    digitalWrite(shcpPin,LOW);
    delayMicroseconds(1);
    digitalWrite(shcpPin,HIGH);
  }

  digitalWrite(stcpPin, LOW);
  delayMicroseconds(1);
  digitalWrite(stcpPin,HIGH);
}
  void MATRIX_setCol(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8){
    digitalWrite(col1Pin, c1);
    digitalWrite(col2Pin, c2);
    digitalWrite(col3Pin, c3);
    digitalWrite(col4Pin, c4);
    digitalWrite(col5Pin, c5);
    digitalWrite(col6Pin, c6);
    digitalWrite(col7Pin, c7);
    digitalWrite(col8Pin, c8);
  }

#include "Wire.h"
#define LATCH 10
#define CLK 9
#define DATA 11

int sensorPin[3] = {2, 3, 4}; //e18
int buttonPin[4] = {5, 6, 7, 8}; //e18
int sensorReading;
int ledPin = 13; //LED monitor waktu read
int lap = 0;
int currentLap = 0;
int previousLap = 0;

boolean TAMulai = 0;
boolean RaceMulai = 0;

int buttonPower;
int oldButton = 0;
int state = 0;

int mss, ss, mm, mspul, mssat, sspul, sssat, mmpul, mmsat;
int curLap1, curLap2, curLap3;

unsigned long start, finished, elapsed;
byte digit[10] = {0b01111110, 0b00110000, 0b01101101, 0b01111001, 0b00110011, 0b01011011, 0b01011111, 0b01110000, 0b01111111, 0b01111011}; //tanpa uln2003
byte type[6] = {0b00000000, 0b00001111, 0b01111101, 0b01000110, 0b01001110, 0b01101111};

void setup() {
  for (int i = 0; i > 3; i++) {
    pinMode (sensorPin[i], INPUT_PULLUP);
  }
  for (int i = 0; i > 4; i++) {
    pinMode (buttonPin[i], INPUT_PULLUP);
  }
  //======================================================================
  //======================================================================
  TCCR2B = TCCR2B & B11111000 | B00000001;
  TCCR1B = TCCR1B & B11111000 | B00000001;
  //======================================================================
  //======================================================================
  Serial.begin (115200);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  Serial.print ("LAP TIMER B-4L");
}

void(*resetFunc)(void) = 0;
void buttonCek() {


  buttonPower = digitalRead(buttonPin[0]);
  //Serial.println(state);
  if (!buttonPower && !oldButton) {
    if (state == 0) {
      Serial.println("mulai mode Time Attack");
      //_timeAttack_();
      state = 1;
    } else {
      Serial.println("mulai mode RACE");
      //_raceTime_();
      state = 0;
    }
    oldButton = 1;
  } else if (buttonPower && oldButton) {
    oldButton = 0;
  }

  int buttonPower1 = digitalRead(buttonPin[3]);
  if (buttonPower1 == 1) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    digitalWrite(LATCH, HIGH);
    delay(500);
    kosongkan();
    delay(500);
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    digitalWrite(LATCH, HIGH);
    delay(500);
    kosongkan();
    delay(500); digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    digitalWrite(LATCH, HIGH);
    delay(500);
    kosongkan();
    delay(500);
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);
    shiftOut(DATA, CLK, MSBFIRST, digit[8]);  // digittiga
    digitalWrite(LATCH, HIGH);
    delay(500);
    kosongkan();
    delay(500);
    resetFunc();
  }
}

void loop() {
  //_timeAttack_();
  buttonCek();

  while (state == 1) {
    _timeAttack_();
    buttonCek();
  }
  while (state == 0) {
    _raceTime_();
    buttonCek();
  }
}

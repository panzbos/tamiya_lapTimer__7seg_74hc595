

void displayResult() {
  float h, m, s, ms, cr;
  unsigned long over;
  elapsed = finished - start ;

  h = int (elapsed / 3600000);
  over = elapsed % 3600000;

  m = int(over / 60000);
  over = over % 60000;

  s = int(over / 1000);

  ms = over % 1000;
  cr = lap;


  Serial.print (m, 0);

  Serial.print ("min");
  Serial.print ("  ");

  Serial.print (s, 0);

  Serial.print ("sec");
  Serial.print ("  ");

  Serial.print (ms, 0);

  Serial.print("ms");
  Serial.print("  ");

  Serial.print("lap : ");

  Serial.println(cr, 0);
  mss = ms;
  ss = s;
  mm = m;
  mspul = mss / 100;
  mssat = mss % 100;
  sspul = ss / 10;
  sssat = ss % 10;
  mmpul = mm / 10;
  mmsat = mm % 10;
  
  kosongkan();  
  
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLK, MSBFIRST, digit[mssat]);  // digittiga
  shiftOut(DATA, CLK, MSBFIRST, digit[mspul]);
  shiftOut(DATA, CLK, MSBFIRST, digit[sssat]);  // digittiga
  shiftOut(DATA, CLK, MSBFIRST, digit[sspul]);
  shiftOut(DATA, CLK, MSBFIRST, digit[mmsat]);  // digittiga
  digitalWrite(LATCH, HIGH);

  Serial.flush();

}
void kosongkan() {

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLK, MSBFIRST, 0b00000000);  // digittiga
  shiftOut(DATA, CLK, MSBFIRST, 0b00000000);
  shiftOut(DATA, CLK, MSBFIRST, 0b00000000);  // digittiga
  shiftOut(DATA, CLK, MSBFIRST, 0b00000000);
  shiftOut(DATA, CLK, MSBFIRST, 0b00000000);  // digittiga
  digitalWrite(LATCH, HIGH);
}


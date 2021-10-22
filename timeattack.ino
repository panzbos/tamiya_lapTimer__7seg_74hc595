
void _timeAttack_() {
  Serial.println("time attack");
  Serial.println(TAMulai);
  if (TAMulai == 0) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, type[2]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, type[1]);
    shiftOut(DATA, CLK, MSBFIRST, type[0]);  // digittiga
    shiftOut(DATA, CLK, MSBFIRST, type[0]);
    shiftOut(DATA, CLK, MSBFIRST, type[0]);  // digittiga
    digitalWrite(LATCH, HIGH);
  }
  if (TAMulai == 0 && digitalRead(sensorPin[0]) == true || digitalRead(sensorPin[1]) == true || digitalRead(sensorPin[2]) == true ) {
    TAMulai = 1;
    Serial.println("asdasdasd  1");
  }
  if ( TAMulai == 1 && lap == 0) {
    start = millis();
  }
  if (TAMulai == 1 && digitalRead(sensorPin[0]) == true || digitalRead(sensorPin[1]) == true || digitalRead(sensorPin[2]) == true ) { // tingkat sensitif
    //
    //   delay(10);
    digitalWrite (ledPin, HIGH);
    currentLap = 1;
    Serial.println("asdasdasd 2");
  }

  else if (TAMulai == 1 && (digitalRead(sensorPin[0]) == false || digitalRead(sensorPin[1]) == false || digitalRead(sensorPin[2]) == false )) {
    finished = millis();
    //  delay(10);
    digitalWrite (ledPin, LOW);
    currentLap = 0;
    displayResult(); // Mobil Tidak melewati sensor
    Serial.println("asdasdasd  3");

  }
  if (TAMulai == 1 && currentLap != previousLap) {
    if (currentLap == 1) {
      lap = lap + 1;
      Serial.println("asdasdasd  4");
    }
  }
  previousLap = currentLap;
  delay(10);

  if (lap == 4) {
    int TADS_mmpul, TADS_mmsat, TADS_sspul, TADS_sssat, TADS_mspul;
    TADS_mmpul = mmpul; TADS_mmsat = mmsat; TADS_sspul = sspul; TADS_sssat = sssat; TADS_mspul = mspul;
    delay(10000);
    Serial.println("asdasdasd  5");
    lap = 0;//displayResult();
    TAMulai = 0;
  }
}


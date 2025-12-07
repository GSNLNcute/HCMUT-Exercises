void loop() {
  int currentSecond = (millis() / 1000) % 60;
  int clockNumber = (currentSecond / 5) + 1;

  if (clockNumber == 1) clockNumber = 12;
  else clockNumber -= 1;

  clearClock();
  displayOnClock(clockNumber);
  delay(1000);
}

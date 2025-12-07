void loop() {
  int sec = (millis() / 1000) % 60;     
  int secPos = (sec / 5) + 1;           
  if (secPos == 1) secPos = 12;
  else secPos -= 1;

  clearClock();
  displayOnClock(secPos);
  delay(1000);

  int min = (millis() / 60000) % 60;     
  int minPos = (min / 5) + 1;            
  if (minPos == 1) minPos = 12; else minPos -= 1;

  clearClock();
  displayOnClock(minPos);
  delay(1000);

  int hour = ((millis() / 3600000) % 12) + 1; 

  clearClock();
  displayOnClock(hour);
  delay(1000);
}

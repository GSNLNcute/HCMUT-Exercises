
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
int ledPins[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup(){
  REP(i, 12) pinMode(ledPins[i], OUTPUT);
}
void displayOnClock(int num){
  if (1 <= num && num <= 12){
    clearClock(); 
    int idx = num - 1;
    digitalWrite(ledPins[index], HIGH);
  }
}
void clearClock(){
  REP(i, 12) digitalWrite(ledPins[i], LOW);
}
void loop() {
  // For your assignment, loop() usually calls the two functions
  // for unit-testing purposes.
}

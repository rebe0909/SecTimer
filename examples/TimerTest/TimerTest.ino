#include arduino.h
#include <SecTimer.h>

SecTimer timer[8];

void setup() {
  // put your setup code here, to run once:
  timer[0].startTimer(15);
}

void loop() {
  // put your main code here, to run repeatedly:
bool timerElapsed = timer[0].hasElapsedTimer();
  if(timerElapsed)
  {
    //Do_something....
  }
}

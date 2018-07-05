#include arduino.h
#include <SecTimer.h>

SecTimer timer[8];

void setup() {
  // put your setup code here, to run once:
  timer[0].startTimer(15);
}

void loop() {
  // put your main code here, to run repeatedly:
bool timer_elapsed = timer[0].hasElapsedTimer();
  if(timer_elapsed)
  {
    //Do_something....
  }
}

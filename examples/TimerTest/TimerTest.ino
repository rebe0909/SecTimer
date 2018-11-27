#include arduino.h
#include <SecTimer.h>

SecTimer timer[8]; //Declare 8 Timers

void setup() 
{

	// put your setup code here, to run once:
	timer[0].startTimer(15); //start one Timer
}

void loop() 
{
	// put your main code here, to run repeatedly:
	bool timerElapsed = timer[0].hasElapsedTimer();
	if(timerElapsed)
	{
		//Do_something....
		timer[0].startTimer(10); //Start Timer again....
	}
}

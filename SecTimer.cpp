/*
	SecTimer.cpp
*/
#include "Arduino.h"
#include "SecTimer.h"


SecTimer::SecTimer()
{
	_timer.starttime = 0;
	_timer.stoptime = 0;
	_timer.interval = 0;
	_timer.running = false;
}

bool SecTimer::hasElapsedTimer (void)
{
	return _hasBeenStartedSekundentimer () && _msTimerGetTimeRemaining() == 0;

}

SecTimer::startTimer(int Sec)
{
	_timer.starttime = millis();
	_timer.stoptime = _timer.starttime + (Sec * 1000);
	_timer.interval = Sec * 1000;
	_timer.running = true;
}

bool SecTimer::_hasBeenStartedSekundentimer (void)
{
	return _timer.starttime != _timer.stoptime || _timer.running;
}

unsigned long SecTimer::_msTimerGetTimeRemaining(void)
{
	unsigned long _current = millis();
	if((_current - _timer.starttime) > _timer.interval) 
	{
		_timer.running = false;
		_timer.interval = 0;
		return 0;
	}
	else
	{
		return _current - _timer.stoptime;
	}
}

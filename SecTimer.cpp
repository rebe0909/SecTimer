/*
	SecTimer.cpp
*/
#include "Arduino.h"
#include "SecTimer.h"

SecTimer::SecTimer()
{
	_timer.starttime_ms = 0;
	_timer.stoptime_ms = 0;
	_timer.interval = 0;
	_timer.running = false;
}
void SecTimer::stopTimer(void)
{
	_timer.running = false;
}

bool SecTimer::hasElapsedTimer (void)
{
	return _hasBeenStartedSecTimer () && _msTimerGetTimeRemaining() == 0;
}

void SecTimer::startTimer(int Sec)
{
	_timer.starttime_ms = millis();
	_timer.stoptime_ms = _timer.starttime_ms + (Sec * 1000);
	_timer.interval = Sec * 1000;
	_timer.running = true;
}

bool SecTimer::_hasBeenStartedSecTimer (void)
{
	return _timer.interval != 0;
}

unsigned long SecTimer::_msTimerGetTimeRemaining(void)
{
	if (!_timer.running) return 0;
	
	unsigned long _current = millis();
	if(_timer.interval == 0 || (_current - _timer.starttime_ms) > _timer.interval )
	{
		_timer.running = false;
		return 0;
	}
	else
	{
		return _current - _timer.stoptime_ms;
	}
}

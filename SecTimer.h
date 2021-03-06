#ifndef __SEC_TIMER__
#define __SEC_TIMER__
#include "Arduino.h"


class SecTimer {

public:
		SecTimer();
		bool trueforSeconds (bool bedingung, int sek);
		bool hasElapsedTimer (void);
		bool hasElapsedOrNotBeenStarted (void);
		bool hasElapsedAndStarted (void);
		void startTimer(int Sec);
		void stopTimer(void);
		typedef struct
		{
			unsigned long starttime_ms;
			unsigned long stoptime_ms;
			unsigned long interval;
			bool running;
		} ms_timer_t;
private:
		ms_timer_t _timer;
		bool _hasBeenStartedSecTimer(void);
		unsigned long _msTimerGetTimeRemaining(void);


};

#endif

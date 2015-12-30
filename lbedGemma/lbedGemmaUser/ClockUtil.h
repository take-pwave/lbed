#ifndef CLOCK_UTIL_H
#define CLOCK_UTIL_H

#include "lbedGemma.h"

class ClockUtil {
public:
	ClockUtil(RTC8564 &rtc, AQCM0802 &lcd, DigitalIn &sw1, DigitalIn &sw2);
	void dispTime();
	void setClock();
private:
	RTC8564		*_rtc;
	AQCM0802	*_lcd;
	DigitalIn	*_sw1;
	DigitalIn	*_sw2;
	char		buf[12];
};
#endif


#include "platform.h"
#include "PinNames.h"
#include "DigitalOut.h"
#include "DigitalIn.h"

DigitalOut::DigitalOut()
{
}

DigitalOut::DigitalOut(PinName pin, const char* name)
{
	setup(pin, name);
}

void DigitalOut::setup(PinName pin, const char* name)
{
	DigitalIn::setup(pin, name);
	if (_gpio) {
		_gpio->DIR |= _mask;
	}
}


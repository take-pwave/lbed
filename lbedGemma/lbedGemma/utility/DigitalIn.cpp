#include "Arduino.h"
#include "lbedGemma.h"

DigitalIn::DigitalIn()
	: _pin(NC)
{
}

DigitalIn::DigitalIn(int pin)
	: _pin(NC)
{
	_setup(pin);
}

void DigitalIn::_setup(int pin)
{
	if (pin != NC){
		_pin = pin;
        pinMode(_pin, INPUT);
    }
}

void DigitalIn::mode(int mode) {
    if (mode == INPUT || mode == INPUT_PULLUP) {
        pinMode(_pin, mode);
    }
}

int DigitalIn::read()
{
	return digitalRead(_pin);
}

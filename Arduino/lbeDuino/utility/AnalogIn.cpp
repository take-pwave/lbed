#include "Arduino.h"
#include "lbed.h"

AnalogIn::AnalogIn()
	: _pin(NC)
{
}

AnalogIn::AnalogIn(int pin)
	: _pin(NC)
{
	_setup(pin);
}

void AnalogIn::_setup(int pin)
{
	if (pin != NC){
		_pin = pin;
    }
}

float AnalogIn::read()
{
    return (float)read_u16()/1023;
}

unsigned short AnalogIn::read_u16()
{
    return analogRead(_pin);
}
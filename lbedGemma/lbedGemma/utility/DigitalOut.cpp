#include "Arduino.h"
#include "lbedGemma.h"

DigitalOut::DigitalOut()
{
}

DigitalOut::DigitalOut(int pin)
{
	DigitalOut::_setup(pin);
}

void DigitalOut::_setup(int pin)
{
	if (pin != NC){
		_pin = pin;
        pinMode(_pin, OUTPUT);
    }
}

void DigitalOut::write(int value)
{
    digitalWrite(_pin, value);
}

int DigitalOut::read(void)
{
    return _value;
}
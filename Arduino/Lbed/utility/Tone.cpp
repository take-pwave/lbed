#include "Arduino.h"
#include "lbed.h"

void (*_tone)(uint8_t, unsigned int, long unsigned int) = tone;
void (*_noTone)(uint8_t pin) = noTone;

Tone::Tone()
	: _pin(NC)
{
}

Tone::Tone(int pin)
	: _pin(NC)
{
	_setup(pin);
}

void Tone::_setup(int pin)
{
	if (pin != NC){
		_pin = pin;
    }
}

void Tone::tone(unsigned int frequency)
{
    (*_tone)(_pin, frequency, 0L);

}

void Tone::tone(unsigned int frequency, unsigned long duration)
{
    (*_tone)(_pin, frequency, duration);
}

void Tone::noTone(void)
{
    (*_noTone)(_pin);
}
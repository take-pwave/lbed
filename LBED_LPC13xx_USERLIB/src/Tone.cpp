/*
 * TOne.cpp
 *
 *  Created on: 2013/07/27
 *      Author: take
 */
#include "Tone.h"
#include "lbed.h"

Tone::Tone(PinName pin) : _out(pin)
{
}

void Tone::tone(unsigned int frequency)
{
	float period = 1.0/frequency;
	noTone();
	_out.period(period);
	_out.write(0.5);
}

void Tone::tone(unsigned int frequency, unsigned long duration)
{
	noTone();
	tone(frequency);
	wait_ms(duration);
	noTone();
}

void Tone::noTone(void)
{
	_out.disable();
}

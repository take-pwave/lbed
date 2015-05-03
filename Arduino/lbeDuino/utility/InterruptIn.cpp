#include "Arduino.h"
#include "lbed.h"

InterruptIn::InterruptIn()
{
}

InterruptIn::InterruptIn(int pin)
{
	DigitalIn::_setup(pin);
}

void InterruptIn::rise(void (*fptr)(void))
{
	attachInterrupt (0, fptr, RISING);
}

void InterruptIn::fall(void (*fptr)(void))
{
	attachInterrupt (0, fptr, FALLING);
}

#include "lbed.h"
#include "LPC8xx.h"			/* LPC8xx Peripheral Registers */
#include "lpc8xx_gpio.h"

DigitalIn::DigitalIn()
	: _pin(NC)
{
}

DigitalIn::DigitalIn(char pin)
	: _pin(NC)
{
	setup(pin);
}

void DigitalIn::setup(char pin)
{
	if (pin != NC && pin != 6 && pin != 7) {	// LPC810の6番と7番は、VCCとGNDに割り当てられている
		_pin = pin;
		LPC_GPIO_PORT->DIR0 &= ~(1 << _pin);
	}
}

int DigitalIn::read()
{
	if (_pin != NC) {
		return LPC_GPIO_PORT->PIN0 & (1 << _pin) ? 1 : 0;
	}
	else
		return (NC);
}

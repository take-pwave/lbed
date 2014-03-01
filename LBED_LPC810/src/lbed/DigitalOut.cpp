#include "lbed.h"
#include "LPC8xx.h"			/* LPC8xx Peripheral Registers */
#include "lpc8xx_gpio.h"

DigitalOut::DigitalOut()
	: _pin(-1)
{
}

DigitalOut::DigitalOut(PinName pin)
	: _pin(-1)
{
	setup(pin);
}
void DigitalOut::setup(PinName pin)
{
	if (pin != NC && pin != 6 && pin != 7) {	// LPC810の6番と7番は、VCCとGNDに割り当てられている
		_pin = pin;
		LPC_GPIO_PORT->DIR0 |= (1 << _pin);
	}
}
void DigitalOut::write(char value)
{
    if (value) {
    	LPC_GPIO_PORT->SET0 = (1 << _pin);
    }
    else {
    	LPC_GPIO_PORT->CLR0 = (1 << _pin);
    }
}

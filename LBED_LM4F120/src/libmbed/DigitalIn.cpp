
#include "platform.h"
#include "PinNames.h"
#include "DigitalIn.h"

DigitalIn::DigitalIn()
	: _pin(-1)
	, _gpio(0)
	, _mask(0)
{
}

DigitalIn::DigitalIn(PinName pin, const char* name)
	: _pin(-1)
	, _gpio(0)
	, _mask(0)
{
	setup(pin, name);
}

void DigitalIn::setup(PinName pin, const char* name)
{
	_pin = pin;
	_gpio = 0;
	_mask = 0;
	if (_pin >= PA_0 && _pin <= PA_7) {
		_gpio = GPIOA;
		_mask = 1 << (_pin - PA_0);
		SYSCTL->RCGCGPIO |= 0x00000001;
	} else if (_pin >= PB_0 && _pin <= PB_7) {
		_gpio = GPIOB;
		_mask = 1 << (_pin - PB_0);
		SYSCTL->RCGCGPIO |= 0x00000002;
	} else if (_pin >= PC_0 && _pin <= PC_7) {
		_gpio = GPIOC;
		_mask = 1 << (_pin - PC_0);
		SYSCTL->RCGCGPIO |= 0x00000004;
	} else if (_pin >= PD_0 && _pin <= PD_7) {
		_gpio = GPIOD;
		_mask = 1 << (_pin - PD_0);
		SYSCTL->RCGCGPIO |= 0x00000008;
	} else if (_pin >= PE_0 && _pin <= PE_5) {
		_gpio = GPIOE;
		_mask = 1 << (_pin - PE_0);
		SYSCTL->RCGCGPIO |= 0x00000010;
	} else if (_pin >= PF_0 && _pin <= PF_4) {
		_gpio = GPIOF;
		_mask = 1 << (_pin - PF_0);
		SYSCTL->RCGCGPIO |= 0x00000020;
	}
	if (_gpio) {
		_gpio->DIR &= ~_mask;
		_gpio->DEN |= _mask;
	}
}

void DigitalIn::mode(PinMode mode) {
	switch (mode) {
	case PullUp:
		_gpio->PUR |= _mask;
		break;
	case PullDown:
		_gpio->PDR |= _mask;
		break;
	case PullNone:
		_gpio->PDR &= ~_mask;	// Not Pull Up
		_gpio->PUR &= ~_mask;	// Not Pull Down
		_gpio->ODR &= ~_mask;	// Not Open Drain
		break;
	case OpenDrain:
		_gpio->ODR |= _mask;
		break;
	default:
		_gpio->PDR &= ~_mask;	// Not Pull Up
		_gpio->PUR &= ~_mask;	// Not Pull Down
		_gpio->ODR &= ~_mask;	// Not Open Drain
	}
}

int DigitalIn::read()
{
	return _gpio && (_gpio->DATA & _mask) ? 1 : 0;
}

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
	_io = 0;
	if (_pin >= P0_0 && _pin <= P0_31) {
		_gpio = LPC_GPIO0;
		_mask = 1 << (_pin - P0_0);
		switch(_pin - P0_0) {
		case 1: _io = &LPC_IOCON->PIO0_1; *_io = 0xd0; break;
		case 2: _io = &LPC_IOCON->PIO0_2; *_io = 0xd0; break;
		case 3: _io = &LPC_IOCON->PIO0_3; *_io = 0xd0; break;
		case 4: _io = &LPC_IOCON->PIO0_4; *_io = 0xd0; break;
		case 5: _io = &LPC_IOCON->PIO0_5; *_io = 0xd0; break;
		case 6: _io = &LPC_IOCON->PIO0_6; *_io = 0xd0; break;
		case 7: _io = &LPC_IOCON->PIO0_7; *_io = 0xd0; break;
		case 8: _io = &LPC_IOCON->PIO0_8; *_io = 0xd0; break;
		case 9: _io = &LPC_IOCON->PIO0_9; *_io = 0xd0; break;
		case 10: _io = &LPC_IOCON->SWCLK_PIO0_10; *_io = 0xd0; break;
		case 11: _io = &LPC_IOCON->R_PIO0_11; *_io = 0xd0; break;
		}
	} else if (_pin >= P1_0 && _pin <= P1_31) {
		_gpio = LPC_GPIO1;
		_mask = 1 << (_pin - P1_0);
		switch(_pin - P1_0) {
		case 0: _io = &LPC_IOCON->R_PIO1_0; *_io = 0xd0; break;
		case 1: _io = &LPC_IOCON->R_PIO1_1; *_io = 0xd0; break;
		case 2: _io = &LPC_IOCON->R_PIO1_2; *_io = 0xd0; break;
		case 3: _io = &LPC_IOCON->SWDIO_PIO1_3; *_io = 0xd0; break;
		case 4: _io = &LPC_IOCON->PIO1_4; *_io = 0xd0; break;
		case 5: _io = &LPC_IOCON->PIO1_5; *_io = 0xd0; break;
		case 6: _io = &LPC_IOCON->PIO1_6; *_io = 0xd0; break;
		case 7: _io = &LPC_IOCON->PIO1_7; *_io = 0xd0; break;
		case 8: _io = &LPC_IOCON->PIO1_8; *_io = 0xd0; break;
		case 9: _io = &LPC_IOCON->PIO1_9; *_io = 0xd0; break;
		}
	} else if (_pin >= P2_0 && _pin <= P2_31) {
		_gpio = LPC_GPIO2;
		_mask = 1 << (_pin - P2_0);
	} else if (_pin >= P3_0 && _pin <= P3_31) {
		_gpio = LPC_GPIO3;
		_mask = 1 << (_pin - P3_0);
	}
	if (_gpio) {
		_gpio->DIR &= ~_mask;
	}
}

void DigitalIn::mode(PinMode mode) {
	switch (mode) {
	case PullUp:
		*_io = 0xd0;	// MODE = 10
		break;
	case PullDown:
		*_io = 0xc8;	// MODE = 01 マニュアルだと0xc8になりそうなのだが、パーフェクト基板本では0x48とある
		break;
	case PullNone:		// MODE = 00
		*_io = 0xc0;
		break;
	case OpenDrain:		// TODO 未実装
		break;
	default:
		*_io = 0xd0;
	}
}

int DigitalIn::read()
{
	return _gpio && (_gpio->DATA & _mask) ? 1 : 0;
}

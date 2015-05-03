#include "platform.h"
#include "PinNames.h"
#include "DigitalIn.h"
#include "InterruptIn.h"

extern "C" {
extern void setIRS0Function(void(*fptr)(void), uint32_t mask);
extern void setIRS1Function(void(*fptr)(void), uint32_t mask);
};

void setup_interrupt(void (*fptr)(void), int rising)  {

}
InterruptIn::InterruptIn()
{
}

InterruptIn::InterruptIn(PinName pin, const char* name)
{
	DigitalIn::setup(pin, name);
}

void InterruptIn::setup_interrupt(void(*fptr)(void), int rising) {
	// LPC1114は、GPIO0, GPIO1のみ
	if (_gpio == LPC_GPIO0) {
		NVIC_EnableIRQ(EINT0_IRQn);
		setIRS0Function(fptr, _mask);
	}
	else if (_gpio == LPC_GPIO1) {
		NVIC_EnableIRQ(EINT1_IRQn);
		setIRS1Function(fptr, _mask);
	}
	_gpio->IS &= ~_mask;	// エッジ・センシティブ
	_gpio->IBE &= ~_mask;	// GIPOnIEVに従う
	if (rising)
		_gpio->IEV |= _mask;	// 立ち上がり
	else
		_gpio->IEV &= ~_mask;// 立ち下がり
	_gpio->IE |= _mask;		// ポートマスク
}

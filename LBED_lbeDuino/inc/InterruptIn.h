#ifndef LBED_INTERRUPTIN_H
#define LBED_INTERRUPTIN_H

#include "platform.h"
#include "PinNames.h"
#include "DigitalIn.h"

class InterruptIn : public DigitalIn {
public:
	InterruptIn();
	InterruptIn(PinName pin, const char* name = 0);
	void rise(void (*fptr)(void)) {
		setup_interrupt(fptr, 1);
	}
	void fall(void (*fptr)(void)){
		setup_interrupt(fptr, 0);
	}
private:
	void setup_interrupt(void(*fptr)(void), int rising);
};

#endif


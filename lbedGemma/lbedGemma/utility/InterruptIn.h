#ifndef LBED_INTERRUPTIN_H
#define LBED_INTERRUPTIN_H

//#include "platform.h"
//#include "PinNames.h"
//#include "DigitalIn.h"

class InterruptIn : public DigitalIn {
public:
	InterruptIn();
	InterruptIn(int pin);
	void rise(void (*fptr)(void));
	void fall(void (*fptr)(void));
};

#endif


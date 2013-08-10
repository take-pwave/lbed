
#ifndef LPC_BUSOUT_H
#define LPC_BUSOUT_H

#include <DigitalOut.h>

//namespace mbed {

class BusOut {
private:
	DigitalOut pins[16];
public:
	BusOut(
		PinName p0,
		PinName p1 = -1,
		PinName p2 = -1,
		PinName p3 = -1,
		PinName p4 = -1,
		PinName p5 = -1,
		PinName p6 = -1,
		PinName p7 = -1,
		PinName p8 = -1,
		PinName p9 = -1,
		PinName p10 = -1,
		PinName p11 = -1,
		PinName p12 = -1,
		PinName p13 = -1,
		PinName p14 = -1,
		PinName p15 = -1);

	void write(int value);
	int read();
};


//} // namespace

#endif



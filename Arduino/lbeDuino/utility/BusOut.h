#ifndef LBED_BUSOUT_H
#define LBED_BUSOUT_H
#include "DigitalOut.h"

class BusOut {
private:
	DigitalOut pins[16];
public:
	BusOut(
		int p0,
		int p1 = -1,
		int p2 = -1,
		int p3 = -1,
		int p4 = -1,
		int p5 = -1,
		int p6 = -1,
		int p7 = -1,
		int p8 = -1,
		int p9 = -1,
		int p10 = -1,
		int p11 = -1,
		int p12 = -1,
		int p13 = -1,
		int p14 = -1,
		int p15 = -1);

	void write(int value);
	int read();
};

#endif

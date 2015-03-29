#include "Arduino.h"
#include "lbed.h"

BusOut::BusOut(
	int p0,
	int p1,
	int p2,
	int p3,
	int p4,
	int p5,
	int p6,
	int p7,
	int p8,
	int p9,
	int p10,
	int p11,
	int p12,
	int p13,
	int p14,
	int p15)
{
	pins[0]._setup(p0);
	pins[1]._setup(p1);
	pins[2]._setup(p2);
	pins[3]._setup(p3);
	pins[4]._setup(p4);
	pins[5]._setup(p5);
	pins[6]._setup(p6);
	pins[7]._setup(p7);
	pins[8]._setup(p8);
	pins[9]._setup(p9);
	pins[10]._setup(p10);
	pins[11]._setup(p11);
	pins[12]._setup(p12);
	pins[13]._setup(p13);
	pins[14]._setup(p14);
	pins[15]._setup(p15);
}

void BusOut::write(int value)
{
	int i;
	for (i = 0; i < 16; i++) {
		pins[i] = (value >> i) & 1;
	}
}

int BusOut::read()
{
	int i;
	int value = 0;
	for (i = 0; i < 16; i++) {
		if (pins[i]) {
			value |= 1 << i;
		}
	}
	return value;
}

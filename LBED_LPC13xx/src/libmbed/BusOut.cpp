
#include <BusOut.h>

//using namespace mbed;

BusOut::BusOut(
	PinName p0,
	PinName p1,
	PinName p2,
	PinName p3,
	PinName p4,
	PinName p5,
	PinName p6,
	PinName p7,
	PinName p8,
	PinName p9,
	PinName p10,
	PinName p11,
	PinName p12,
	PinName p13,
	PinName p14,
	PinName p15)
{
	pins[0].setup(p0);
	pins[1].setup(p1);
	pins[2].setup(p2);
	pins[3].setup(p3);
	pins[4].setup(p4);
	pins[5].setup(p5);
	pins[6].setup(p6);
	pins[7].setup(p7);
	pins[8].setup(p8);
	pins[9].setup(p9);
	pins[10].setup(p10);
	pins[11].setup(p11);
	pins[12].setup(p12);
	pins[13].setup(p13);
	pins[14].setup(p14);
	pins[15].setup(p15);
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



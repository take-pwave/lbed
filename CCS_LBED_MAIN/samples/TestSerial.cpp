#include"lbed.h"

int main(void) {
	lbed_setup();

	Serial pc(PA_1, PA_0);
	DigitalOut myled(LEDG);
	pc.baud(19200);
	pc.println("Hello");
	while (1) {
		char c = pc.read();
		pc.write(c + 1);
		myled = !myled;
	}
	return 0;
}


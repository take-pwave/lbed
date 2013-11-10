#include"lbed.h"


int main(void) {
	Serial 		pc(PA_1, PA_0);
	AnalogIn 	in(PE_3);
	DigitalOut 	myled(LEDG);
	pc.baud(19200);
	pc.println("Hello");
	while (1) {
		unsigned short val = in.read_u16();
		pc.printf("Sensor = %d\n", (int)val);
		myled = !myled;
		wait_ms(1000);
	}
	return 0;
}


#include"lbed.h"
#include "LM73.h"

int main(void) {
	DigitalOut myled(LEDG);
	LM73 lm73(PB_3, PB_2);

	while (1) {
		float t = lm73.read();
		myled = !myled;
		wait_ms(1000);
	}
}

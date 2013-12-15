#include "lbed.h"

DigitalOut led(LEDG);
void flip() {
	led = !led;
}

int main() {
	Ticker flipper;
	flipper.attach(&flip, 1.0);

	while(1)
		continue;
}

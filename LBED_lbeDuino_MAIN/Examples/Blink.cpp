#include	"lbed.h"

DigitalOut led(D13);

void setup() {
}

void loop() {
	led = !led;
    wait_ms(1000);
}

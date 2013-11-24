#include "lbed.h"

int main(void) {
	lbed_setup();

	PwmOut led(LEDR);
    led = 0.5;
    while(1) {
        led = led + 0.02;
        if(led >= 1.0) {
            led = 0.0;
        }
        wait_ms(80);
   }
}

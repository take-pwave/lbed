#include "lbed.h"

int main(void) {
	lbed_setup();

    DigitalOut myled(LEDG);
    while(1) {
        myled = ! myled;
        wait_ms(1000);
    }
}

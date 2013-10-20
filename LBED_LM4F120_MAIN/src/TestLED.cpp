#include "lbed.h"

int main(void) {
    DigitalOut myled(LEDG);
    while(1) {
        myled = ! myled;
        wait_ms(1000);
    }
}

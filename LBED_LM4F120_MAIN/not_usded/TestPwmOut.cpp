#include "lbed.h"

int main(void) {
    PwmOut led(PB_5);
    led = 0.5;
    while(1) {
        led = led + 0.02;
        if(led >= 1.0) {
            led = 0.0;
        }
        wait_ms(80);
   }
}

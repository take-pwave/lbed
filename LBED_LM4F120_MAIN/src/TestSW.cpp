#include "lbed.h"

int main(void) {
	DigitalIn	sw1(SW1);
	sw1.mode(PullUp);
    DigitalOut	myled(LEDG);
    while(1) {
        myled = !sw1;	// SW1を押すとLow=0になるので、押したときにLEDを付けるために!を付ける。
        wait_ms(1000);
    }
}

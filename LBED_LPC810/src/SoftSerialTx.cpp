/*
  Blink
  1秒間LEDを点灯し、1秒間消灯を繰り返す
 */

#ifdef __USE_CMSIS
#include "LPC8xx.h"
#endif

#include <cr_section_macros.h>

#include "lbed.h"
// 2400bps
#define SERIAL_TIME_PER_BIT1    208
#define SERIAL_TIME_PER_BIT2    208

void serialWrite(DigitalOut pin, uint8_t data) {
	pin = 0;
	wait_us(SERIAL_TIME_PER_BIT1);

	uint8_t i;
	for (int cnt = 0, i=0x01; cnt < 8; i<<=1, cnt++) {
		if (data & i)
			pin = 1;
		else
			pin = 0;
		wait_us(SERIAL_TIME_PER_BIT2);
	}
	pin = 1;
	wait_us(SERIAL_TIME_PER_BIT1+2);
}

int main(void) {
	// lbedライブラリの初期化
	lbed_setup();
	// 8番ピンにLEDを接続
	DigitalOut	led(P5);
	while(1) {
		//serialWrite(led, '*');

		serialWrite(led, 'H');
		serialWrite(led, 'e');
		serialWrite(led, 'l');
		serialWrite(led, 'l');
		serialWrite(led, 'o');
		serialWrite(led, '\n');
		wait_ms(1000);	// 1秒待つ

	}
    return 0 ;
}

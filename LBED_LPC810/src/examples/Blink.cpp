/*
  Blink
  1秒間LEDを点灯し、1秒間消灯を繰り返す
 */

#ifdef __USE_CMSIS
#include "LPC8xx.h"
#endif

#include <cr_section_macros.h>

#include "lbed.h"

int main(void) {
	// lbedライブラリの初期化
	lbed_setup();
	// 8番ピンにLEDを接続
	DigitalOut	led(P8);
	while(1) {
		led = !led;		// LEDを反転する
		wait_ms(1000);	// 1秒待つ
	}
    return 0 ;
}

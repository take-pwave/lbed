/*
  ButtonSwitch
  スイッチを押すとLEDを点灯する
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
	// 5番ピンにSWを接続
	DigitalIn	sw(P5);
	while(1) {
		led = !sw;		// SWは、アクティブローなので、!を付けて反転
		wait_ms(200);	// 0.2秒待つ
	}
    return 0 ;
}

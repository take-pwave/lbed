/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC8xx.h"
#endif

#include <cr_section_macros.h>

#include "lbed.h"
#include "AQCM0802.h"

int main(void) {
	// lbedライブラリの初期化
	lbed_setup();
	/* I2C用スイッチマトリックスの設定 */
	//I2C_SwitchMatrix_Init();
	// ここから通常のプログラムイングと同様
	DigitalOut	led(0);
	DigitalIn	sw(1);
	//AQCM0802	lcd(0, 4);

	//lcd.print("Hello");
	while(1) {
		led = !sw;
		wait_ms(200);
	}
    return 0 ;
}

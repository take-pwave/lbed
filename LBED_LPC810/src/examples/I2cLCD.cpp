/*
  I2cLCD
  秋月AQCM0802を使ったI2cLCDの例題
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
	I2C_SwitchMatrix_Init();
	// 5番ピンにLEDを接続
	DigitalOut	led(P5);
	// 8番ピンSDA, 2番ピンSCL
	AQCM0802	lcd(P8, P2);
	// カウンター
	int	counter = 0;
	lcd.print("Hello");
	while(1) {
		led = !led;
		lcd.locate(0, 1);
		lcd.print("cnt=");
		lcd.print(counter++);
		wait_ms(1000);
	}
    return 0 ;
}

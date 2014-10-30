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
#include "RTC8664.h"

int main(void) {
	// lbedライブラリの初期化
	lbed_setup();
	/* I2C用スイッチマトリックスの設定 */
	I2C_SwitchMatrix_Init();
	// 5番ピンにLEDを接続
	DigitalOut	led(P5);
	// 8番ピンSDA, 2番ピンSCL
	AQCM0802	lcd(P8, P2);
	lcd.setup();
	// RTCタイマー
	RTC8664		rtc(P8, P2);
	rtc.setup();
	rtc.set_time(0x45, 0x59, 0x23, 0x31, 0x06, 0x12, 0x10);
	// アラームセット
	rtc.set_alarm(0x00, 0x02);
	// カウンター
	rtc.clear_alarm_flag();
	int     pS = 0xff;
	while(1) {
		rtc.read_rtc();
		if (pS != rtc.S) {
			lcd.locate(0, 0);
			lcd.printf("%02x/%02x/%02x", rtc.Y, rtc.N, rtc.D);
			lcd.locate(0, 1);
			lcd.printf("%02x:%02x:%02x", rtc.H, rtc.M, rtc.S);
			led = !led;
			pS = rtc.S;
		}
		wait_ms(100);
	}
    return 0 ;
}

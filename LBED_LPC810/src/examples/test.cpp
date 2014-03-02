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

#define BOD_PD              (0x1<<3)
#define WDT_OSC_PD          (0x1<<6)
#define MCU_DEEP_SLEEP      1

extern "C" {
extern void PMU_Init( void );
extern void PMU_Sleep( uint32_t SleepMode, uint32_t SleepCtrl );
}

int main(void) {
	uint32_t regVal;
	// lbedライブラリの初期化
	lbed_setup();
	/* I2C用スイッチマトリックスの設定 */
	I2C_SwitchMatrix_Init();
	PMU_Init();
	  regVal = LPC_SYSCON->PDSLEEPCFG;
	  //regVal &= ~(WDT_OSC_PD | BOD_PD);
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
		//PMU_Sleep( MCU_DEEP_SLEEP, regVal );
		wait_ms(1000);
	}
    return 0 ;
}

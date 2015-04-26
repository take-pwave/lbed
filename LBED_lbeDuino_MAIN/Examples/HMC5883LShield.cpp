#include "lbed.h"
#include "AQCM0802.h"
#include "HMC5883L.h"

// D13番ピンにLEDを接続
DigitalOut	led(D13);
// D8番ピンSDA, D9番ピンSCL
AQCM0802	lcd(D8, D9);
HMC5883L	sensor(D8, D9);

// タクトスイッチ
DigitalIn	sw1(D2);
DigitalIn	sw2(D3);

int	showHead = 0;

void setup() {
	sw1.mode(PullUp);
	sw2.mode(PullUp);
	lcd.setup();
	sensor.setup();
	sensor.setGain(1);
	lcd.print("HMC5883L setup");
	wait_ms(2000);
}

void loop() {
	led = !led;
	lcd.cls();
	lcd.locate(0, 1);
	sensor.measure();
	if (!sw1) {
		showHead = !showHead;
	}
	// sw2を押すとSelf Testを実行する
	if (!sw2) {
		lcd.locate(0, 0); lcd.print("Self Test");
		lcd.locate(0, 1); lcd.print("Begin");
		int ret = sensor.selfTest();
		lcd.cls();
		lcd.locate(0, 0); lcd.print("Self Test"); lcd.locate(0, 1);
		if (ret == -1) {
			lcd.print("Error");
		}
		else if (ret == 0) {
			lcd.print("Failed");
		}
		else {
			lcd.print("Succeeded");
		}
		wait_ms(2000);
	}
	else if (showHead) {
		lcd.locate(0, 0);
		lcd.print("Head:");
		lcd.print(sensor.getHead(), 1);
		lcd.locate(0, 1);
		lcd.print("Absolute:");
		lcd.print(sensor.getAbs(), 1);
	}
	else {
		lcd.locate(0, 0);
		lcd.print("X:");
		lcd.print(sensor.x, 1);
		lcd.locate(0, 1);
		lcd.print("Y:");
		lcd.print(sensor.y, 1);
	}
	wait_ms(500);
}

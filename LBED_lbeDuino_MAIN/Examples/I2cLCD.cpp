#include "lbed.h"
#include "AQCM0802.h"

// D13番ピンにLEDを接続
DigitalOut	led(D13);
// D8番ピンSDA, D9番ピンSCL
AQCM0802	lcd(D8, D9);
// カウンター
int	counter = 0;

void setup() {
	lcd.setup();
	lcd.print("Hello");
}

void loop() {
	led = !led;
	lcd.locate(0, 1);
	lcd.print("cnt=");
	lcd.print(counter++);
	wait_ms(1000);
}

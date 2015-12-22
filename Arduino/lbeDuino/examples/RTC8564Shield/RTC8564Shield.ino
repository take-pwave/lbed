#include "Wire.h"
#include "lbed.h"
#include "AQCM0802.h"
#include "RTC8564.h"
//#include "Tone.h"

AQCM0802 lcd(A4, A5);  // sda, scl, reset
RTC8564 rtc(A4, A5);
Tone beep(D3);
InterruptIn sw1(D2);

int hasWakeup = 0;
int pin2 = 2;

// 割込処理関数
void pin2Interrupt(void) {
	hasWakeup = 1;
}

int disp_time() {
	lcd.cls();
	lcd.locate(0, 0);
	lcd.printf("%d/%02d/%02d", rtc.Y, rtc.M, rtc.D);
	lcd.locate(0, 1);
	lcd.printf("%02d:%02d:%02d", rtc.h, rtc.m, rtc.s);
}

void setup() {
	sw1.mode(PullUp);
	lcd.setup();
	rtc.setup();
	// rtc.set_time(2014, 12, 31, 23, 59, 45);
	lcd.locate(0, 0);
	lcd.print("Set Alarm!");
	wait_ms(1000);
	// アラームセット時間hに関係なく（0x80）、毎0秒にアラームをセット
	rtc.set_alarm(0x80, 0);
	sw1.fall(pin2Interrupt);
}

void loop() {
	wait_ms(1000);
	rtc.read_rtc();
	disp_time();

	if (hasWakeup) {
		hasWakeup = 0;
		lcd.locate(0, 1);
		lcd.println("Wake Up!");
		beep.tone(440, 500);
		rtc.set_alarm(0x80, (rtc.m + 1) % 60);
	}
}

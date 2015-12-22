/*
 * BME280Shield.cpp
 *
 *  Created on: 2015/04/19
 *      Author: take
 */
#include "Wire.h"
#include "lbed.h"
#include "AQCM0802.h"
#include "BME280.h"

// D13番ピンにLEDを接続
DigitalOut	led(D13);
// D8番ピンSDA, D9番ピンSCL
AQCM0802	lcd(D8, D9);
BME280		sensor(D8, D9);

// タクトスイッチ
DigitalIn	sw1(D2);
DigitalIn	sw2(D3);

int		last_mode = 0;
char	degree = 0xdf;
void setup() {
	sw1.mode(PullUp);
	sw2.mode(PullUp);
	lcd.setup();
	sensor.setup();
	lcd.locate(0, 0); lcd.print("BME280");
	lcd.locate(0, 1); lcd.print("Demo");
	wait_ms(2000);
}

void loop() {
	led = ! led;
    if (sw1 == 1) {
        if (last_mode == 0)
            lcd.cls();
        lcd.locate(0, 0);
        lcd.print(sensor.getTemperature(), 2);
        lcd.print(degree); lcd.print("C");
        lcd.locate(0, 1);
        lcd.print(sensor.getHumidity(), 2); lcd.print("%");
        last_mode = 1;
    }
    else {
        if (last_mode == 1)
            lcd.cls();
        lcd.locate(0, 0);
        lcd.print(sensor.getTemperature(), 2);
        lcd.print(degree); lcd.print("C");
        lcd.locate(0, 1);
        lcd.print(sensor.getPressure(), 2); lcd.print("hPa");
        last_mode = 0;
    }
    wait_ms(1000);
}




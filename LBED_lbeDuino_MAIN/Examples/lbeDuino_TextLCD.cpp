#include "lbed.h"
#include "TextLCD.h"

DigitalOut led(D13);
TextLCD lcd(D0, D1, D2, D3, D4, D5);	// rs, e, d4-7
int	count = 0;

void setup() {
	lcd.print("Hello World!");
}

void loop() {
	lcd.locate(0, 1);
	lcd.print("Count=");
	lcd.print(count++);
	led = !led;
    wait_ms(1000);
}

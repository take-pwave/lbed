#include "lbed.h"
#include "TextLCD.h"

int main(void) {
	int	count = 0;
    DigitalOut myled(LEDG);
    TextLCD lcd(PA_6, PA_7, PA_2, PA_3, PA_4, PA_5);	// rs, e, d4-7

    lcd.print("Hello World!");
    while(1) {
    	lcd.locate(0, 1);
    	lcd.print("Count=");
    	lcd.print(count++);
        myled = ! myled;
        wait_ms(1000);
    }
}

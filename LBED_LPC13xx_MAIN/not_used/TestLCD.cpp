#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"
#include "TextLCD.h"

int main(void) {
	int	count = 0;
    wait_init();
    DigitalOut myled(LED2);
    TextLCD lcd(p26, p22, p14, p6, p5, p25);	// rs, e, d4-7

    lcd.print("Hello World!");
    while(1) {
    	lcd.locate(0, 1);
    	lcd.print("Count=");
    	lcd.print(count++);
        myled = ! myled;
        wait_ms(1000);
    }
}

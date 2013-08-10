#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"
#include "TextLCD.h"

int main(void) {
	int	count = 0;
    wait_init();
    DigitalOut myled(LED2);
    TextLCD lcd(P1_5, P1_6, P1_7, P0_1, P2_0, P1_8);	// rs, e, d4-7

    lcd.print("Hello World!");
    while(1) {
    	lcd.locate(0, 1);
    	lcd.print("Count=");
    	lcd.print(count++);
        myled = ! myled;
        wait_ms(1000);
    }
}

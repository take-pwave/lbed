#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP;

#include"lbed.h"
#include "TextLCD.h"
#include "LM75B.h"

int main(void) {
	wait_init();
	DigitalOut myled(LED2);
    TextLCD lcd(p26, p22, p14, p6, p5, p25);	// rs, e, d4-7
	LM75B lm75b(p28, p27);
	lcd.print("Hello World");

	while (1) {
		float t = lm75b.read();
		lcd.locate(0, 1);
		lcd.print("Temp:");
		lcd.print(t);
		myled = !myled;
		wait_ms(1000);
	}
	return 0;
}

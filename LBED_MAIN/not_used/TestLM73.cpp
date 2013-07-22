#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP;

#include"lbed.h"
#include "TextLCD.h"
#include "LM73.h"

int main(void) {
	wait_init();
	DigitalOut myled(LED2);
	TextLCD lcd(p8, p25, p24, p26, p29, p30); // rs, e, d4-7
	LM73 lm73(p28, p27);
	lcd.print("Hello World");

	while (1) {
		float t = lm73.read();
		lcd.locate(0, 1);
		lcd.print("Temp:");
		lcd.print(t);
		myled = !myled;
		wait_ms(1000);
	}
	return 0;
}

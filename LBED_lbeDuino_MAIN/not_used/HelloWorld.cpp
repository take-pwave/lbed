#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include"lbed.h"
#include "LM73.h"

DigitalOut myled(LED2);
TextLCD lcd(p8, p25, p24, p26, p29, p30);
LM73 lm73(p28, p27);
SPI spi(p5, p6, p7);

int main(void) {
    wait_init();
    char *buf = "Hello world\n";
    float t = lm73.read();
    lcd.print(buf);

    volatile int	value;
    spi.frequency(500000);
    while(*buf) {
    	value = *buf++;
    	spi.write(value);
    }

    while(1) {
    	t = lm73.read();
    	lcd.locate(0, 1);
    	lcd.print("Temp:");
    	lcd.print(t);
        myled = ! myled;
        wait_ms(2000);
    }
    return 0 ;
}

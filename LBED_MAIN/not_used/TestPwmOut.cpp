#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"
//#include "MARMEX_OB_oled.h"

PwmOut led(p26);
//MARMEX_OB_oled oled(p5, p7, p24, p27, p28);

int main(void) {
    wait_init();
    while(1) {
        led = led + 0.01;
        wait_ms(200);
        if(led >= 1.0) {
            led = 0.0;
        }
    }
}

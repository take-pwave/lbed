#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"

int main(void) {
    wait_init();
    PwmOut led(p26);
    led = 0.0;
    while(1) {
        led = led + 0.05;
        wait_ms(200);
        if(led >= 1.0) {
            led = 0.0;
        }
    }
}

#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"

int main(void) {
    wait_init();
    DigitalOut myled(LED2);
    while(1) {
        myled = ! myled;
        wait_ms(1000);
    }
}

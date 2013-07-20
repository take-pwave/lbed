#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"
#include "MARMEX_OB_oled.h"

int main(void) {
    wait_init();
    MARMEX_OB_oled oled(p5, p7, p30, p29, p26);

    oled.background( 0x000000 );
    oled.cls();

    int colorbar_width  = MARMEX_OB_oled::WIDTH / 8;
    for ( int i = 0; i < 8; i++ )
        oled.fill( colorbar_width * i, 0, colorbar_width, MARMEX_OB_oled::HEIGHT,
((i & 0x4) ? 0xFF0000 : 0x000000) | ((i & 0x2) ? 0x00FF00 : 0x000000) | ((i & 0x1) ? 0x0000FF : 0x000000) );

    oled.fill(  50,  50,  64,  64, 0xCCCCCC );;
    oled.locate(0, 3);
    oled.print("Hello World!");

    while(1) {
    }
}

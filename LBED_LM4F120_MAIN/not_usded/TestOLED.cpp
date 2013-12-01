#include <math.h>
#include "lbed.h"
#include "MARMEX_OB_oled.h"

int main(void) {
    MARMEX_OB_oled oled(PD_3, PD_0, J1_8, J1_9, J1_10);	// mosi, sclk, cs, rst, power_control

    oled.background( 0x000000 );
    oled.cls();

    int colorbar_width  = MARMEX_OB_oled::WIDTH / 8;
    for ( int i = 0; i < 8; i++ )
        oled.fill( colorbar_width * i, 0, colorbar_width, MARMEX_OB_oled::HEIGHT,
        		((i & 0x4) ? 0xFF0000 : 0x000000) | ((i & 0x2) ? 0x00FF00 : 0x000000) | ((i & 0x1) ? 0x0000FF : 0x000000) );

    oled.fill(  50,  50,  64,  64, 0xCCCCCC );;
    oled.locate(0, 3);
    oled.print("Hello World!");

    for (int i = 0; i < MARMEX_OB_oled::WIDTH; i++ ) {
    	oled.pixel( i, 80 + sinf( (float)i / 5.0 ) * 10, 0x000000 );
    }

    while(1) {
    }
}

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"

int main(void) {
    wait_init();
    DigitalOut myled(LED2);
	SerialCDC pc(USBTX, USBRX);
	pc.baud(9600);
	// キー入力を待つ
	pc.read();

    AnalogIn	agnd(P1_2);
    AnalogIn	dc(P1_10);
    while(1) {
    	int	d0 = agnd.read_u16();
    	int v0 = 1250*1024/d0;
    	int	d1 = dc.read_u16();
    	int v1 = v0*d1/1024;
    	pc.printf("Ch3:%04d[VDD=%04dmV]  Ch6:%04d[%04dmV]\n", d0, v0, d1, v1);
        myled = ! myled;
        wait_ms(1000);
    }
}

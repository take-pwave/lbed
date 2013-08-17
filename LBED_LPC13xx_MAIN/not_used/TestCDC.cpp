#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lbed.h"


int main(void) {
	wait_init();
	DigitalOut myled( LED2);

	SerialCDC pc(USBTX, USBRX);
	pc.baud(9600);
	// キー入力を待つ
	pc.read();

	pc.println("Hello");
	while (1) {
		char c = pc.read();
		pc.write(c + 1);
		myled = !myled;
	}
	return 0;
}


#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP;

#include"lbed.h"

DigitalOut myled( LED1);

int main(void) {
	wait_init();
	Serial pc(p9, p10);
	pc.baud(9600);
	pc.println("Hello");
	while (1) {
		char c = pc.read();
		pc.write(c + 1);
		myled = !myled;
	}
	return 0;
}


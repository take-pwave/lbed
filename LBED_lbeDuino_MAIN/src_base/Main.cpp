/*
 * Main.cpp
 *
 *  Created on: 2015/01/12
 *      Author: take
 */

#include<cr_section_macros.h>
#include<NXP/crp.h>
__CRP extern const unsigned int CRP_WORD = CRP_NO_CRP;
#include	"lbed.h"

extern void setup();
extern void loop();

int main(void) {
	//wait_init();
	setup();

	while(1) {
		loop();
	}
	/* not reached */
	return 0;
}





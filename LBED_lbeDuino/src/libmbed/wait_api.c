#include <LPC11xx.h>
#include "wait_api.h"

void wait_init() {
	unsigned int SYSTEM_CLOCK = SystemCoreClock/1000;
	SysTick->LOAD  = SYSTEM_CLOCK/2 - 1;
	SysTick->VAL   = 0;
}

void wait_ms(int ms) {
	int	i;
	SysTick->CTRL  |= (1<<0);
	for(i=0; i<ms; i++){
		while(!((SysTick->CTRL>>16)&0x01));
	}
	SysTick->CTRL  &= ~(1<<1);
}

void wait_us(int us) {
	int i = 12*us;	// 48MHｚの4クロックでループを回ると仮定
	while(i-- > 0)
			;
}

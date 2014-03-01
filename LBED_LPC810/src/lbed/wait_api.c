#include "LPC8xx.h"			/* LPC8xx Peripheral Registers */
#include "wait_api.h"

void wait_init() {
	// IRC 12MHz
	/* Configure the core clock/PLL via CMSIS */
	SystemCoreClockUpdate();
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
	volatile long i = 8*us;	// ビジーウェイト用の仮の値
	while (i-- > 0)
		continue;
}

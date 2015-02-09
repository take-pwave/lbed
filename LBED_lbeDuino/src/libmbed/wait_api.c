#include <LPC11xx.h>
#include "wait_api.h"

volatile uint32_t msTicks;                            /* counts 1ms timeTicks */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;                        /* increment counter necessary in Delay() */
}

void wait_init() {
	// millisのために、LM4F120版に合わせた
	if (SysTick_Config(SystemCoreClock / 1000)) { /* Setup SysTick Timer for 1 msec interrupts  */
		while (1);                                  /* Capture error */
	}

}

void wait_ms(int ms) {
	// millisのために、LM4F120版に合わせた
	uint32_t curTicks;

	curTicks = msTicks;
	while ((msTicks - curTicks) < ms);
}

void wait_us(int us) {
	volatile int i = 12*us;	// 48MHｚの4クロックでループを回ると仮定
	while(i-- > 0)
			;
}

unsigned long	millis() {
	return msTicks;
}

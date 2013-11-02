#include <platform.h>
#include "wait_api.h"

volatile uint32_t msTicks;							/* counts 1ms timeTicks */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;                        				/* increment counter necessary in Delay() */
}

void wait_init() {
	  if (SysTick_Config(SystemCoreClock / 1000)) { /* Setup SysTick Timer for 1 msec interrupts  */
	    while (1);                                  /* Capture error */
	  }
}

void wait_ms(int ms) {
	  uint32_t curTicks;

	  curTicks = msTicks;
	  while ((msTicks - curTicks) < ms);
}

void wait_us(int us) {
	volatile long i = 8*us;	// 仮の値
	while (i-- > 0)
		continue;
}

void wait(double s) {
	double dms = s*1000.0;
	int	ms = (int)dms;
	int us = (int)((dms - ms)*1000.0);
	wait_ms(ms);
	wait_us(us);
}

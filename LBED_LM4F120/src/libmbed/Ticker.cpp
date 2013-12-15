#include "Ticker.h"
#include "LM4F_handler.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"

Ticker::Ticker()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_32_BIT_PER);
	IntEnable(INT_TIMER0A);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	IntMasterEnable();
}

void Ticker::attach (void(*fptr)(void), float t)
{
	TimerDisable(TIMER0_BASE, TIMER_A);
	setUserTimer0AFunc(fptr);
	_period = t;
	unsigned long p = (unsigned long)(SysCtlClockGet()*_period);
	TimerLoadSet64(TIMER0_BASE, p -1);		// periodをセット
	TimerEnable(TIMER0_BASE, TIMER_A);
}

void Ticker::detach()
{
	TimerDisable(TIMER0_BASE, TIMER_A);
	clearUserTimer0AFunc();
	TimerEnable(TIMER0_BASE, TIMER_A);
}

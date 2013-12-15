#include "platform.h"
#include "PinNames.h"
#include "LM4F_handler.h"

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

void (*userTimer0AFunc)();

void Timer0AIntHandler(void) {
	// Clear the timer interrupt
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	// Call the userTimer0Func
	if (userTimer0AFunc)
		(*userTimer0AFunc)();
}

void setUserTimer0AFunc(void (*func)(void)) {
	userTimer0AFunc = func;
}

void clearUserTimer0AFunc() {
	userTimer0AFunc = 0;
}

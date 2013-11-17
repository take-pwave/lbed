#include "lbed.h"

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"

int main(void) {
    unsigned long ulPeriod, dutyCycle, preScale;

    // 40 MHz system clock
    // SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|
    //    SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    ulPeriod = 1000;	//1000;
    dutyCycle = 250;	//250;
    preScale = 2;

    // Configure PB6 as T0CCP0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinConfigure(GPIO_PF1_T0CCP1);
    GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1);

    // Configure timer
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
    TimerPrescaleSet(TIMER0_BASE, TIMER_B, preScale -1);
	TimerPrescaleMatchSet(TIMER0_BASE, TIMER_B, preScale -1);
    TimerLoadSet(TIMER0_BASE, TIMER_B, ulPeriod -1);
    TimerMatchSet(TIMER0_BASE, TIMER_B, dutyCycle); // PWM
    TimerEnable(TIMER0_BASE, TIMER_B);

    while(1) { // The following code varies the duty cycle over time
        TimerMatchSet(TIMER0_BASE, TIMER_B, dutyCycle++);

        if(dutyCycle >= ulPeriod - 1)
            dutyCycle = 0;

        SysCtlDelay(50000);
    }
/*
    PwmOut led(LEDR);
    led = 0.5;
    while(1) {
        led = led + 0.05;
        if(led >= 1.0) {
            led = 0.0;
        }
        wait_ms(200);
   }
*/
}

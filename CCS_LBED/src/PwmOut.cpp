#include "platform.h"
#include "PinNames.h"
#include "PwmOut.h"

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"

#define	NULL	(0L)

PwmOut::PwmOut(PinName pin) :
	_name(NULL), _period(0.02), _pulsewidth(0.0), _value(0.0), _scale(0), _base(0), _timer(0)
{
	_pin = pin;
	setup(_period);
}

void PwmOut::setup(float period) {
	_period = period;
	unsigned long p = (uint32_t)(SystemCoreClock*_period);
	// 16bitの範囲内で制御できるようにprescaleを変更する
	if (p > (unsigned long)0xFFFF)
		_scale = p/0x10000 + 1;
	else
		_scale = 1;
	unsigned long matchTime = (unsigned long)((_period - _pulsewidth)*SystemCoreClock/_scale)-1;
	switch (_pin) {
	case LEDR:	// T0CCP1
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		GPIOPinConfigure(GPIO_PF1_T0CCP1);
		GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
		_base = TIMER0_BASE;
		_timer = TIMER_B;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
		break;
	case LEDB:	// T1CCP0
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		GPIOPinConfigure(GPIO_PF2_T1CCP0);
		GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_2);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
		_base = TIMER1_BASE;
		_timer = TIMER_A;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
		break;
	case LEDG:	// T1CCP1
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		GPIOPinConfigure(GPIO_PF3_T1CCP1);
		GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_3);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
		_base = TIMER1_BASE;
		_timer = TIMER_B;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
		break;
	case PB_5:	// T1CCP1
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB5_T1CCP1);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_5);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
		_base = TIMER1_BASE;
		_timer = TIMER_B;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
		break;
	case PB_0:	// T2CCP0
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB0_T2CCP0);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_0);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
		_base = TIMER2_BASE;
		_timer = TIMER_A;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
		break;
	case PB_1:	// T2CCP1
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB1_T2CCP1);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_1);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
		_base = TIMER2_BASE;
		_timer = TIMER_B;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
		break;
	case PB_2:	// T3CCP0
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB2_T3CCP0);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_2);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
		_base = TIMER3_BASE;
		_timer = TIMER_A;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
		break;
	case PB_7:	// T0CCP1
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB7_T0CCP1);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_7);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
		_base = TIMER0_BASE;
		_timer = TIMER_B;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
		break;
	case PB_6:	// T0CCP0
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB6_T0CCP0);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_6);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
		_base = TIMER0_BASE;
		_timer = TIMER_A;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
		break;
	case PB_3:	// T3CCP1
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		GPIOPinConfigure(GPIO_PB3_T3CCP1);
		GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_3);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
		_base = TIMER3_BASE;
		_timer = TIMER_B;
		TimerConfigure(_base, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
		break;
	}
	TimerPrescaleSet(_base, _timer, _scale -1);		// prescaleをセット
	TimerPrescaleMatchSet(_base, _timer, _scale -1);
	TimerLoadSet(_base, _timer, p/_scale -1);		// periodをセット
	TimerMatchSet(_base, _timer, matchTime);
	TimerEnable(_base, _timer);
}

void PwmOut::period(float period) {
	//setup(period);
	_period = period;
	unsigned long p = (uint32_t)(SystemCoreClock*_period);
	// 16bitの範囲内で制御できるようにprescaleを変更する
	if (p > (unsigned long)0xFFFF)
		_scale = p/0x10000 + 1;
	else
		_scale = 1;
	unsigned long matchTime = (unsigned long)((_period - _pulsewidth)*SystemCoreClock/_scale)-1;
	TimerPrescaleSet(_base, _timer, _scale -1);		// prescaleをセット
	TimerPrescaleMatchSet(_base, _timer, _scale -1);
	TimerLoadSet(_base, _timer, p/_scale -1);		// periodをセット
	TimerMatchSet(_base, _timer, matchTime);
	TimerEnable(_base, _timer);
}

void PwmOut::pulsewidth(float seconds) {
	_pulsewidth = seconds;
	uint32_t matchTime = (uint32_t)((_period - _pulsewidth)*SystemCoreClock/_scale)-1;
	TimerMatchSet(_base, _timer, matchTime);
}

void PwmOut::disable(void) {
	TimerDisable(_base, _timer);
}



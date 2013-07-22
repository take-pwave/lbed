#include "platform.h"
#include "PinNames.h"
#include "PwmOut.h"

#include <LPC11xx.h>
#include "type.h"
#include "_timer16.h"
#include "_timer32.h"

#define	NULL	(0L)

PwmOut::PwmOut(PinName pin) :
	_name(NULL), _period(0.02), _pulsewidth(0.0), _value(0.0)
{
	_pin = pin;
	setup(_period);
	/* Enable AHB clock to the GPIO domain. */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
}

void PwmOut::setup(float period) {
	_period = period;
	uint32_t p = (uint32_t)(SystemCoreClock*_period);
	uint32_t matchTime = (_period - _pulsewidth)*p;
	// PWMに使えるのは、p21-23, p26です。
	switch (_pin) {
	case p21:	// PIO0_10	CT16M2
		init_timer16PWM(0, p, MATCH2, 0);
		setMatch_timer16PWM (0, 2, matchTime);
		enable_timer16(0);
		break;
	case p22:	// PIO0_2	CT16B0C0
		break;
	case p23:	// PIO0_11	CT32M3
		init_timer32PWM(0, p, MATCH3);
		setMatch_timer32PWM(0, 3, matchTime);
		enable_timer32(0);
		break;
	case p25:	// PIO1_8	CT16B1C0
		break;
	case p26:	// PIO1_9	CT16M0
		init_timer16PWM(1, p, MATCH0, 0);
		setMatch_timer16PWM (1, 0, matchTime);
		enable_timer16(1);
		break;
	}
}

void PwmOut::period(float seconds) {
	setup(seconds);
}

void PwmOut::pulsewidth(float seconds) {
	_pulsewidth = seconds;
	uint32_t p = (uint32_t)(SystemCoreClock*_period);
	uint32_t matchTime = (_period - _pulsewidth)*p;
	// PWMに使えるのは、p21, 23, p26です。
	switch (_pin) {
	case p21:	// PIO0_10	CT16M2 注意）LPC-Linkを使っている場合には設定してはいけない！
		disable_timer16(0);
		setMatch_timer16PWM (0, 2, matchTime);
		enable_timer16(0);
		break;
	case p22:	// PIO0_2	CT16B0C0
		break;
	case p23:	// PIO0_11	CT32M3
		disable_timer32(0);
		setMatch_timer32PWM(0, 3, matchTime);
		enable_timer32(0);
		break;
	case p25:	// PIO1_8	CT16B1C0
		break;
	case p26:	// PIO1_9	CT16M0
		disable_timer16(1);
		setMatch_timer16PWM (1, 0, matchTime);
		enable_timer16(1);
		break;
	}
}



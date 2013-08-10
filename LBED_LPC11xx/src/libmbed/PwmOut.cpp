#include "platform.h"
#include "PinNames.h"
#include "PwmOut.h"

#include <LPC11xx.h>
#include "type.h"
#include "_timer16.h"
#include "_timer32.h"

#define	NULL	(0L)

PwmOut::PwmOut(PinName pin) :
	_name(NULL), _period(0.02), _pulsewidth(0.0), _value(0.0), _scale(1)
{
	_pin = pin;
	setup(_period);
	/* Enable AHB clock to the GPIO domain. */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
}

void PwmOut::setup(float period) {
	_period = period;
	uint32_t p = (uint32_t)(SystemCoreClock*_period);
	// 16bitの範囲内で制御できるようにprescaleを変更する
	if (p > (SystemCoreClock/1000))
		_scale = 1000;
	else
		_scale = 1;
	uint32_t matchTime = (uint32_t)((_period - _pulsewidth)*SystemCoreClock/_scale)-1;
	// PWMに使えるのは、p21-23, p26です。
	switch (_pin) {
	case p21:	// PIO0_10	CT16M2
		LPC_TMR16B0->PR = _scale -1;	// prescaleをセット
		init_timer16PWM(0, p/_scale, MATCH2, 0);
		setMatch_timer16PWM (0, 2, matchTime);
		enable_timer16(0);
		break;
	case p22:	// PIO0_2	CT16B0C0
		break;
	case p23:	// PIO0_11	CT32M3
		LPC_TMR32B0->PR = _scale -1;	// prescaleをセット
		init_timer32PWM(0, p/_scale, MATCH3);
		setMatch_timer32PWM(0, 3, matchTime);
		enable_timer32(0);
		break;
	case p25:	// PIO1_8	CT16B1C0
		break;
	case p26:	// PIO1_9	CT16M0
		LPC_TMR16B1->PR = _scale -1;	// prescaleをセット
		init_timer16PWM(1, p/_scale, MATCH0, 0);
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
	uint32_t matchTime = (uint32_t)((_period - _pulsewidth)*SystemCoreClock/_scale)-1;
	// PWMに使えるのは、p21, 23, p26です。
	switch (_pin) {
	case p21:	// PIO0_10	CT16M2 注意）LPC-Linkを使っている場合には設定してはいけない！
		setMatch_timer16PWM (0, 2, matchTime);
		break;
	case p22:	// PIO0_2	CT16B0C0
		break;
	case p23:	// PIO0_11	CT32M3
		setMatch_timer32PWM(0, 3, matchTime);
		break;
	case p25:	// PIO1_8	CT16B1C0
		break;
	case p26:	// PIO1_9	CT16M0
		setMatch_timer16PWM (1, 0, matchTime);
		break;
	}
}

void PwmOut::disable(void) {
	// PWMに使えるのは、p21, 23, p26です。
	switch (_pin) {
	case p21:	// PIO0_10	CT16M2 注意）LPC-Linkを使っている場合には設定してはいけない！
		disable_timer16(0);
		break;
	case p22:	// PIO0_2	CT16B0C0
		break;
	case p23:	// PIO0_11	CT32M3
		disable_timer32(0);
		break;
	case p25:	// PIO1_8	CT16B1C0
		break;
	case p26:	// PIO1_9	CT16M0
		disable_timer16(1);
		break;
	}
}



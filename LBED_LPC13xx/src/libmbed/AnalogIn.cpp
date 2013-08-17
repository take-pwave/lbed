
#include "platform.h"
#include "PinNames.h"
#include "AnalogIn.h"

#define ADC_CLK	4400000	/* set to 4.4Mhz */
AnalogIn::AnalogIn()
	: _channel(-1)
{
}

AnalogIn::AnalogIn(PinName pin, const char* name)
	: _channel(-1)
{
	setup(pin, name);
}

void AnalogIn::setup(PinName pin, const char* name)
{
	DigitalIn::setup(pin, name);
	/* Disable Power down bit to the ADC block. */
	LPC_SYSCON->PDRUNCFG &= ~(0x1<<4);
	/* Enable AHB clock to the ADC. */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<13);

	switch(pin) {
	case P0_11:
		_channel = 0; break;
	case P1_0:
		_channel = 1; break;
	case P1_1:
		_channel = 2; break;
	case P1_2:
		_channel = 3; break;
	case P1_3:
		_channel = 4; break;
	case P1_4:
		_channel = 5; break;
	case P1_10:
		_channel = 6; break;
	case P1_11:
		_channel = 7; break;
	}
	if (_channel >= 0) {
		*_io &= ~0x8F; /* ADC I/O config */
		if (_channel < 5)
			*_io |= 0x02;  	/* ADC IN0~IN4 */
		else
			*_io |= 0x01;	/* ADC IN5~IN7 */

		LPC_ADC->CR = ( 0x01 << 0 ) |  /* SEL=1,select channel 0~7 on ADC0 */
		  ( ( SystemCoreClock / ADC_CLK - 1 ) << 8 ) |  /* CLKDIV = Fpclk / 1000000 - 1 */
		  ( 0 << 16 ) | 		/* BURST = 0, no BURST, software controlled */
		  ( 0 << 17 ) |  		/* CLKS = 0, 11 clocks/10 bits */
		  ( 0 << 24 ) |  		/* START = 0 A/D conversion stops */
		  ( 0 << 27 );		/* EDGE = 0 (CAP/MAT singal falling,trigger A/D conversion) */
	}
}

float AnalogIn::read()
{
	return (float)read_u16()/(float)(0xFFFF);
}

unsigned short AnalogIn::read_u16()
{
	if (_channel >= 0) {
		unsigned int dat;

		LPC_ADC->CR = 0x01000f00 | (1 << _channel);
		do {
			dat = LPC_ADC->GDR;
		} while (!(dat & 0x80000000));
		return ((dat >> 6) &0x3ff);
	}
	else
		return 0;
}


#include "platform.h"
#include "PinNames.h"
#include "AnalogIn.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"

#define SAMPLE_SPS		SYSCTL_ADCSPEED_250KSPS	/* 250K Sampling/Sec */
#define	SEQUENCE_NUM	3						/* 1 sampling/call */
uint32_t	AnalogIn::_b_mask = 0;
uint32_t	AnalogIn::_d_mask = 0;
uint32_t	AnalogIn::_e_mask = 0;

AnalogIn::AnalogIn()
	: _pin(-1)
{
}

AnalogIn::AnalogIn(PinName pin, const char* name)
	: _pin(-1)
{
	setup(pin, name);
}

void AnalogIn::setup(PinName pin, const char* name)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	SysCtlADCSpeedSet(SAMPLE_SPS);
	ADCSequenceDisable(ADC0_BASE, SEQUENCE_NUM);

	if (pin >= PE_0 && pin <= PE_5) {
		_gpio = GPIO_PORTE_BASE;
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
		switch (pin) {
			case PE_3:
				_channel = ADC_CTL_CH0;
				_pin = 3;
				break;
			case PE_2:
				_channel = ADC_CTL_CH1;
				_pin = 2;
				break;
			case PE_1:
				_channel = ADC_CTL_CH2;
				_pin = 1;
				break;
			case PE_0:
				_channel = ADC_CTL_CH3;
				_pin = 0;
				break;
			case PE_5:
				_channel = ADC_CTL_CH8;
				_pin = 5;
				break;
		}
		AnalogIn::_e_mask |= 1 << _pin;
		// ピンタイプをADCにセット
		GPIOPinTypeADC(_gpio, AnalogIn::_e_mask);
	}
	else if (pin >= PB_4 && pin <= PB_5) {
		_gpio = GPIO_PORTB_BASE;
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		switch (pin) {
			case PB_4:
				_channel = ADC_CTL_CH10;
				_pin = 4;
				break;
			case PB_5:
				_channel = ADC_CTL_CH11;
				_pin = 5;
				break;
		}
		AnalogIn::_b_mask |= 1 << _pin;
		// ピンタイプをADCにセット
		GPIOPinTypeADC(_gpio, AnalogIn::_b_mask);
	}
	else if (pin >= PD_0 && pin <= PD_3) {
		_gpio = GPIO_PORTD_BASE;
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
		switch (pin) {
			case PD_0:
				_channel = ADC_CTL_CH7;
				_pin = 0;
				break;
			case PD_1:
				_channel = ADC_CTL_CH6;
				_pin = 1;
				break;
			case PD_3:
				_channel = ADC_CTL_CH5;
				_pin = 3;
				break;
			case PD_4:
				_channel = ADC_CTL_CH4;
				_pin = 4;
				break;
		}
		AnalogIn::_d_mask |= 1 << _pin;
		// ピンタイプをADCにセット
		GPIOPinTypeADC(_gpio, AnalogIn::_e_mask);
	}
	// ADC0をシーケンス3を割り込み不可にする
	ADCSequenceDisable(ADC0_BASE, SEQUENCE_NUM);
	// ADC0のシーケンスを最大優先にセット
	ADCSequenceConfigure(ADC0_BASE, SEQUENCE_NUM, ADC_TRIGGER_PROCESSOR, 0);
	// 1ステップで1サンプリングにセット
	ADCSequenceStepConfigure(ADC0_BASE, SEQUENCE_NUM, 0, _channel | ADC_CTL_IE | ADC_CTL_END);
	// ADC0をシーケンス3を割り込み可能にする
	ADCSequenceEnable(ADC0_BASE, SEQUENCE_NUM);
	// ADC0をシーケンス3の割り込みフラグをクリア
	ADCIntClear(ADC0_BASE, SEQUENCE_NUM);
}

float AnalogIn::read()
{
	return (float)read_u16()/(float)(4096);
}

unsigned short AnalogIn::read_u16()
{
	if (_gpio) {
		ADCIntClear(ADC0_BASE, SEQUENCE_NUM);
		ADCProcessorTrigger(ADC0_BASE, SEQUENCE_NUM);
		while(!ADCIntStatus(ADC0_BASE, SEQUENCE_NUM, false)) {
		}
		ADCSequenceDataGet(ADC0_BASE, SEQUENCE_NUM, &_value);
		return ((short)(_value&0x0FFF));
	}
	else
		return 0;
}

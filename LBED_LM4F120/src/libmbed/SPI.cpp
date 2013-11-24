#include "platform.h"
#include "PinNames.h"
#include "SPI.h"

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/pin_map.h"

SPI::SPI(PinName mosi, PinName miso, PinName sclk, const char *name) :
	_mosi(-1), _miso(-1), _sclk(-1), _bits(8), _hz(1000000L), _mode(0) {
	_name = (char *) name;
	// ssi0
	if (mosi == PA_5 && miso == PA_4 && sclk == PA_2) {
	    //ssi0デバイスとポートAを利用可能にする
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	    // ssi0デバイスとポートAをSSIを使えるようにピンを設定する
	    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
	    GPIOPinConfigure(GPIO_PA4_SSI0RX);
	    GPIOPinConfigure(GPIO_PA5_SSI0TX);
	    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_5);
	    _base = SSI0_BASE;
	}
	// ssi2
	else if (mosi == PB_7 && miso == PB_6 && sclk == PB_4) {
	    //ssi2デバイスとポートBを利用可能にする
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	    // ssi2デバイスとポートBをSSIを使えるようにピンを設定する
	    GPIOPinConfigure(GPIO_PB4_SSI2CLK);
	    GPIOPinConfigure(GPIO_PB6_SSI2RX);
	    GPIOPinConfigure(GPIO_PB7_SSI2TX);
	    GPIOPinTypeSSI(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7);
	    _base = SSI2_BASE;
	}
	// デフォルトはssi1
	else {	// mosi == PD_3 && miso == PD_2 && sclk == PD_0
	    //ssi1デバイスとポートDを利用可能にする
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI1);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	    // ssi1デバイスとポートDをSSIを使えるようにピンを設定する
	    GPIOPinConfigure(GPIO_PD0_SSI1CLK);
	    GPIOPinConfigure(GPIO_PD2_SSI1RX);
	    GPIOPinConfigure(GPIO_PD3_SSI1TX);
	    GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3);
	    _base = SSI1_BASE;
	}
    _ulMode = SSI_FRF_MOTO_MODE_0;
	SSIClockSourceSet(_base,SSI_CLOCK_SYSTEM);
	SSIConfigSetExpClk(_base, SysCtlClockGet(), _ulMode, SSI_MODE_MASTER, _hz, _bits);
	SSIEnable(_base);
}

void SPI::format(int bits, int mode) {
	_bits = bits;
	_mode = mode;
	switch (_mode) {
	case 0:	// POL:0, PHA:0
		_ulMode = SSI_FRF_MOTO_MODE_0; break;
	case 1: // POL:0, PHA:1
		_ulMode = SSI_FRF_MOTO_MODE_1; break;
	case 2: // POL:1, PHA:0
		_ulMode = SSI_FRF_MOTO_MODE_2; break;
	case 3: // POL:1, PHA:1
		_ulMode = SSI_FRF_MOTO_MODE_3; break;
	}
	SSIDisable(_base);
	SSIConfigSetExpClk(_base, SysCtlClockGet(), _ulMode, SSI_MODE_MASTER, _hz, _bits);
	SSIEnable(_base);
}

void SPI::frequency(int hz) {
	_hz = hz;
	SSIDisable(_base);
	SSIConfigSetExpClk(_base, SysCtlClockGet(), _ulMode, SSI_MODE_MASTER, _hz, _bits);
	SSIEnable(_base);
}

int SPI::write(int value) {
	unsigned long _value;
	SSIDataPut(_base, value);
	while (SSIBusy(_base))
		continue;
	// SPIのライトは、リード兼用なので、書き込んだ後は読み込みを行う
	SSIDataGet(_base, &_value);
	return (int)_value;
}



#include "Serial.h"
#include "PinNames.h"
//#define	PART_LM4F120H5QR	1

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"

Serial::Serial()
	: _tx(-1)
	, _rx(-1)
{
	setup(PA_1, PA_0, "default");
}

Serial::Serial(PinName tx, PinName rx, const char *name)
	: _tx(-1)
	, _rx(-1)
{
	setup(tx, rx, name);
}

void Serial::setup(PinName tx, PinName rx, const char *name)
{
	_tx = tx;
	_rx = rx;
	_available = false;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    // Configure the GPIO pin muxing for the UART function.
    // This is only necessary if your part supports GPIO pin function muxing.
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    // Since GPIO A0 and A1 are used for the UART function, they must be
    // configured for use as a peripheral function (instead of GPIO).
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
}

void Serial::baud(unsigned int baudrate) {
    // Configure the UART for baudrate, 8-N-1 operation.
    // This function uses SysCtlClockGet() to get the system clock
    // frequency.
	unsigned long sysclock = SysCtlClockGet();
    UARTConfigSetExpClk(UART0_BASE, sysclock, baudrate,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));
	_available = true;									// 利用可能にセット
}

void Serial::begin(unsigned int baudrate) {
	baud(baudrate);
}

int Serial::write(const char c) {
	UARTCharPut(UART0_BASE, c);
	return 1;
}

int Serial::read() {
	return UARTCharGet(UART0_BASE);
}

int Serial::available() {
	return UARTCharsAvail(UART0_BASE);
}

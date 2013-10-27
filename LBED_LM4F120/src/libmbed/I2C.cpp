#include "platform.h"
#include "PinNames.h"
#include "I2C.h"

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

I2C::I2C(PinName sda, PinName scl, const char *name) {
	_name = (char *) name;
	// The I2C0 peripheral must be enabled before use.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
	// For this example I2C0 is used with PortB[3:2].
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	// Configure the pin muxing for I2C0 functions on port B2 and B3.
	// GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	// GPIOPinConfigure(GPIO_PB3_I2C0SDA);
	// Select the I2C function for these pins.
	GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);	//	I2CSCL
	GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);	//	I2CSDA
	// Enable and initialize the I2C0 master module. True=400Kbps, False=100Kbps
	I2CMasterInitExpClk(I2C0_MASTER_BASE, SysCtlClockGet(), false);
}

int I2C::read(int address, char *data, int length, bool repeated) {
	unsigned char addr = (unsigned char)address>>1;
	I2CMasterSlaveAddrSet( I2C0_MASTER_BASE, addr, true);   // false = write, true = read
    if (length == 1) {
    	I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
        // Wait until done transmitting
        while( I2CMasterBusy(I2C0_MASTER_BASE));
        *data = I2CMasterDataGet(I2C0_MASTER_BASE);
    }
    else {
    	for (int i = 0; i < length; i++) {
    		if (i == 0)
    			I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
    		else if (i == length-1)
    			I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
    		else
    			I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
            // Wait until done transmitting
            while( I2CMasterBusy(I2C0_MASTER_BASE));
            *data++ = I2CMasterDataGet(I2C0_MASTER_BASE);
    	}
    }
    return length;
}

// この関数の使い方がよく分からないので、たぶんこんな感じという実装
int I2C::read(int ack) {
	I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
    // Wait until done transmitting
    while( I2CMasterBusy(I2C0_MASTER_BASE));
	return I2CMasterDataGet(I2C0_MASTER_BASE);;
}

int I2C::write(int address, const char *data, int length, bool repeated) {
	unsigned char addr = (unsigned char)address>>1;
	I2CMasterSlaveAddrSet( I2C0_MASTER_BASE, addr, false);   // false = write, true = read
    if (length == 1) {
    	I2CMasterDataPut( I2C0_MASTER_BASE, *data);
    	I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_SINGLE_SEND);
        // Wait until done transmitting
        while( I2CMasterBusy(I2C0_MASTER_BASE));
    }
    else {
    	for (int i = 0; i < length; i++) {
    		I2CMasterDataPut( I2C0_MASTER_BASE, *data++);
    		if (i == 0)
    			I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);
    		else if (i == length-1)
    			I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
    		else
    			I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
            // Wait until done transmitting
            while( I2CMasterBusy(I2C0_MASTER_BASE));
    	}
    }
    return length;
}

// この関数の使い方がよく分からないので、たぶんこんな感じという実装
int I2C::write(int ack) {
	I2CMasterDataPut( I2C0_MASTER_BASE, ack);
	I2CMasterControl( I2C0_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
    while( I2CMasterBusy(I2C0_MASTER_BASE));
    return 1;
}


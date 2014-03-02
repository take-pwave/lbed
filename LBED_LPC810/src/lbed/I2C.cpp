#include "lpc8xx_i2c.h"
#include "lbed.h"

extern "C" {
volatile uint8_t I2CMasterTXBuffer[I2C_BUFSIZE];
volatile uint8_t I2CMasterRXBuffer[I2C_BUFSIZE];
volatile uint8_t I2CSlaveTXBuffer[I2C_BUFSIZE];
volatile uint8_t I2CSlaveRXBuffer[I2C_BUFSIZE];
volatile uint32_t I2CMonBuffer[I2C_MONBUFSIZE];
volatile uint32_t I2CReadLength, I2CWriteLength;
}

I2C::I2C(char sda, char scl)
{
	setup();
}

void I2C::setup()
{
    uint32_t regVal;

	/*connect the I2C SCL and SDA signals to port pins(P0.3-P0.2)*/
    regVal = LPC_SWM->PINASSIGN7 & ~(0xFFUL<<24);
	LPC_SWM->PINASSIGN7 = regVal | (0 << 24);	/* P0.0 is I2C SDA, ASSIGN0(31:24) */
	regVal = LPC_SWM->PINASSIGN8 & ~(0xFF<<0);
	LPC_SWM->PINASSIGN8 = regVal | (4 << 0);	/* P0.4 is I2C SCL. ASSIGN0(7:0) */
	LPC_IOCON->PIO0_0 |= (0x1<<10);				/* Enable pseudo open drain */
	LPC_IOCON->PIO0_4 |= (0x1<<10);				/* Enable pseudo open drain */

	/* Enable I2C clock */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<5);
	/* Toggle peripheral reset control to I2C, a "1" bring it out of reset. */
	LPC_SYSCON->PRESETCTRL &= ~(0x1<<6);
	LPC_SYSCON->PRESETCTRL |= (0x1<<6);

	// 400KHz
//	I2C_MstInit(LPC_I2C, I2C_FMODE_PRE_DIV, CFG_MSTENA, 0x00);
	// 100KHz
	I2C_MstInit(LPC_I2C, I2C_SMODE_PRE_DIV, CFG_MSTENA, 0x00);
}

int I2C::write(int address, const char *data, int length, bool repeated)
{
	unsigned char addr = (unsigned char)address>>1;
	for (int i = 0; i < length; i++)
		I2CMasterTXBuffer[i] = *data++;
	I2C_MstSend( LPC_I2C, address, (uint8_t *)I2CMasterTXBuffer, length);
	return length;
}

int I2C::read(int address, char *data, int length, bool repeated)
{
	I2CMasterTXBuffer[0] = *data;
	unsigned char addr = (unsigned char)address>>1;
	I2C_MstSendRcv( LPC_I2C, address, (uint8_t *)I2CMasterTXBuffer, 1, (uint8_t *)I2CMasterRXBuffer, length );
	for (int i = 0; i < length; i++)
		data[i] = I2CMasterRXBuffer[i];
    return length;
}

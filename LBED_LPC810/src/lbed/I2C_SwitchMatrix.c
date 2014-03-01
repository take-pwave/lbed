#include "LPC8xx.h"

void I2C_SwitchMatrix_Init()
{
	// トラ技2014/02号の実験用プリント基板でI2Cを使う設定
    /* Enable SWM clock */
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);

    /* Pin Assign 8 bit Configuration */
    /* I2C0_SDA */
    LPC_SWM->PINASSIGN7 = 0x00ffffffUL;
    /* I2C0_SCL */
    LPC_SWM->PINASSIGN8 = 0xffffff04UL;

    /* Pin Assign 1 bit Configuration */
    /* SWCLK */
    /* SWDIO */
    /* RESET */
    LPC_SWM->PINENABLE0 = 0xffffffb3UL;
}

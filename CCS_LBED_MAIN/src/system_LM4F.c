/********************************************************************************/
/*!
	@file			system_LM4F.c
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        1.00
    @date           2012.09.30
	@brief          CMSIS Cortex-M4 Device Peripheral Access Layer Source File
                    for TI Stellaris Devices.

    @section HISTORY
		2012.09.30	V1.00	Start Here.

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

#include "LM4F120H5QR.h"
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#define ROM_FPUEnable                                                         \
        ((void (*)(void))ROM_FPUTABLE[0])

#define ROM_FPULazyStackingEnable                                             \
        ((void (*)(void))ROM_FPUTABLE[4])

#define ROM_SysCtlClockSet                                                    \
        ((void (*)(unsigned long ulConfig))ROM_SYSCTLTABLE[23])

#define ROM_SysCtlClockGet                                                    \
        ((unsigned long (*)(void))ROM_SYSCTLTABLE[24])

/* Defines -------------------------------------------------------------------*/

#define	HSE_VALUE	16000000
/* Variables -----------------------------------------------------------------*/
/*!< System Clock Frequency (Core Clock)*/
uint32_t SystemCoreClock = HSE_VALUE;

/* Constants -----------------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

/**************************************************************************/
/*! 
    @brief	Get Core Clock Frequency .
	@param	none
    @retval	none      
*/
/**************************************************************************/
void SystemCoreClockUpdate(void)
{
	/* Get Current HCLK */
	SystemCoreClock = ROM_SysCtlClockGet();	
}

/**************************************************************************/
/*! 
    @brief	Setup the microcontroller system.
			Initialize the System.
	@param	none
    @retval	none      
*/
/**************************************************************************/
void SystemInit(void)
{
	/* FPU settings ------------------------------------------------------------*/
	#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
	 /*SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));*/
	 /* set CP10 and CP11 Full Access */
	 ROM_FPUEnable();
     ROM_FPULazyStackingEnable();
	#endif
  
	/* Set Up Clock */
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);
}

void lbed_setup()
{
	extern void wait_init();

	SystemInit();
	SystemCoreClockUpdate();
    wait_init();
	ROM_FPUEnable();
    ROM_FPULazyStackingEnable();
}

/* End Of File ---------------------------------------------------------------*/

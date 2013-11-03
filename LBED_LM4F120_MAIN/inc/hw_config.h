/********************************************************************************/
/*!
	@file			hw_config.h
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        2.00
    @date           2012.07.09
	@brief          For TI Stellaris EK-LM4F120XL Launchpad!

    @section HISTORY
		2012.09.15	V1.00	Start Here.
		2013.07.09	V2.00	Fixed Typo.

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/
#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H 0x0200

#ifdef __cplusplus
 extern "C" {
#endif

/* General Inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>

#include "LM4F120H5QR.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"

#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"

/* Function Inclusion */
#include "systick_stellaris.h"
#include "uart_support.h"

/* High Level Function */
/*
#include "xprintf.h"
#include "diskio.h"
#include "ff.h"
#include "ff_support.h"
#include "term_io.h"
#include "display_if.h"
#include "display_if_support.h"
#include "ts_fileloads.h"
*/

/* Macros */
#define countof(a)   (sizeof(a) / sizeof(*(a)))
/* See systick.h */
#define Cyclic_Exec()	{			\
		}
		

/* Lanchpad LED Settings */
#define RED_GPIO_PIN            GPIO_PIN_1
#define BLUE_GPIO_PIN           GPIO_PIN_2
#define GREEN_GPIO_PIN          GPIO_PIN_3

#define LED_GPIO_BASE			GPIOF_AHB_BASE
#define LED_GPIO				GPIOF_AHB
#define LED_GPIO_CLK			SYSCTL_PERIPH_GPIOF

#define LED_RED_On()			LED_GPIO->DATA |=   RED_GPIO_PIN
#define LED_RED_Off()			LED_GPIO->DATA &=  ~RED_GPIO_PIN
#define LED_BLU_On()			LED_GPIO->DATA |=   BLUE_GPIO_PIN
#define LED_BLU_Off()			LED_GPIO->DATA &=  ~BLUE_GPIO_PIN
#define LED_GRN_On()			LED_GPIO->DATA |=   GREEN_GPIO_PIN
#define LED_GRN_Off()			LED_GPIO->DATA &=  ~GREEN_GPIO_PIN


/* Externals */

extern __IO uint16_t CmdKey;
extern void Set_System(void);
extern void NVIC_Configuration(void);
extern void LED_Configuration(void);
extern void KEY_Configuration(void);
extern void initialise_monitor_handles();

#ifdef __cplusplus
}
#endif

#endif  /* __HW_CONFIG_H */

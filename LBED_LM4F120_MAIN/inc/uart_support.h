/********************************************************************************/
/*!
	@file			uart_support.h
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        1.00
    @date           2012.10.24
	@brief          Based on ChaN's FatFs LPC2388 Example Thanks!

    @section HISTORY
		2012.10.24	V1.00	Start Here.

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/
#ifndef __UART_SUPPORT_H
#define __UART_SUPPORT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* General Inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

/* uC Specific Inclusion */
#include "LM4F120H5QR.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"

#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"

/* USART Definition */
/* Should Change for Your Board Definitions! */
#define UART_BUFSIZE		192					/* UART TX&RX BufferSize in byte	*/
#define UART_BAUDLATE		230400UL			/* UART Baudrate 				  	*/
#define UARTx				UART0				/* UART Numberq 				  	*/
#define UARTx_IRQn			UART0_IRQn			/* Interrupt Number for UART(NVIC)	*/
#define UARTx_BASE			UART0_BASE			/* UART Register Base Address 	 	*/
#define UARTx_IRQHandler 	UART0_Handler		/* UART IRQ Handler 			  	*/
#define UARTx_RxPin_Alt		GPIO_PA0_U0RX		/* UARTx GPIO Altanate Definition 	*/
#define UARTx_TxPin_Alt		GPIO_PA1_U0TX		/* UARTx GPIO Altanate Definition 	*/
#define UARTx_GPIO_RxPin	GPIO_PIN_0			/* UARTx GPIO Pin Definition 	  	*/
#define UARTx_GPIO_TxPin	GPIO_PIN_1			/* UARTx GPIO Pin Definition 	  	*/
#define UARTx_GPIO_BASE		GPIOA_BASE			/* UARTx GPIO PORT Definition 	  	*/
#define UARTx_PortClk		SYSCTL_PERIPH_GPIOA /* UARTx GPIO CLK Definition 	  	*/
#define UARTx_PeriphClk		SYSCTL_PERIPH_UART0 /* UARTx PERITH CLK Definition 	  	*/

/* General Definition */
/* UART Fifo Structure */
typedef struct {
	uint16_t	rptr;
	uint16_t	wptr;
	uint16_t	count;
	uint8_t		buff[UART_BUFSIZE];
}UartFifo_t;

/* Funcion Prototypes */
extern void conio_init(uint32_t baudrate);
extern void putch(uint8_t c);
extern uint8_t getch(void);
extern uint8_t keypressed(void);
extern void cputs(char *s);
extern void cgets(char *s, int bufsize);

/* Externs */
extern volatile UartFifo_t  TxFifo,RxFifo;

#ifdef __cplusplus
}
#endif

#endif	/* __UART_SUPPORT_H */

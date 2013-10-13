/********************************************************************************/
/*!
	@file			startup_LM4F.s
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        1.00
    @date           2012.09.30
	@brief          TI Stellaris LM4F Series Startup ASM Code				@n
					Based On STM32F107VCT6's Startup.

    @section HISTORY
		2012.09.30	V1.00	Start Here.
		
    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/

	.syntax unified
	.cpu cortex-m4
	.fpu softvfp
	.thumb

.global	g_pfnVectors
.global	Default_Handler

/* start address for the initialization values of the .data section. 
defined in linker script */
.word	_sidata
/* start address for the .data section. defined in linker script */  
.word	_sdata
/* end address for the .data section. defined in linker script */
.word	_edata
/* start address for the .bss section. defined in linker script */
.word	_sbss
/* end address for the .bss section. defined in linker script */
.word	_ebss



/**************************************************************************/
/*! 
    @brief	This is the code that gets called when the processor first	@n
			starts execution following a reset event.
	@param	none
    @retval	none
*/
/**************************************************************************/
    .section	.boot,"ax",%progbits
	.weak	Reset_Handler
	.type	Reset_Handler, %function
Reset_Handler:	

/* Copy the data segment initializers from flash to SRAM */  
	movs	r1, #0
	b  		LoopCopyDataInit
CopyDataInit:
	ldr  	r3, =_sidata
	ldr  	r3, [r3, r1]
	str  	r3, [r0, r1]
	adds 	r1, r1, #4
LoopCopyDataInit:
	ldr		r0, =_sdata
	ldr  	r3, =_edata
	adds  	r2, r0, r1
	cmp  	r2, r3
	bcc  	CopyDataInit
	ldr  	r2, =_sbss
	b  		LoopFillZerobss

/* Zero fill the bss(block started by symbol) segment. */  
FillZerobss:
	movs  	r3, #0
	str  	r3, [r2], #4
LoopFillZerobss:
	ldr  	r3, = _ebss
	cmp  	r2, r3
	bcc 	 FillZerobss
 
/* Call the clock system intitialization function.*/
	bl  	SystemInit

/* Call the application's entry point.*/
	bl  	main
	bx  	lr    

.size	Reset_Handler, .-Reset_Handler



/**************************************************************************/
/*! 
    @brief	This is the code that gets called when the processor receives  @n
			an unexpected interrupt.  This simply enters an infinite loop, @n
            preserving the system state for examination by a debugger.
	@param	none
    @retval	none
*/
/**************************************************************************/
    .section	.text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
	b	Infinite_Loop
	.size	Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M3.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/    
 	.section .isr_vector,"a",%progbits
	.type	g_pfnVectors, %object
	.size	g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
    .word   _estack		               /* Top of Stack 				   */
    .word   Reset_Handler              /* Reset Handler                */
    .word  NMI_Handler                 /* NMI Handler                  */
    .word  HardFault_Handler           /* Hard Fault Handler           */
    .word  MemManage_Handler           /* MPU Fault Handler            */
    .word  BusFault_Handler            /* Bus Fault Handler            */
    .word  UsageFault_Handler          /* Usage Fault Handler          */
    .word  0                           /* Reserved                     */
    .word  0                           /* Reserved                     */
    .word  0                           /* Reserved                     */
    .word  0                           /* Reserved                     */
    .word  SVC_Handler                 /* SVCall Handler               */
    .word  DebugMon_Handler            /* Debug Monitor Handler        */
    .word  0                           /* Reserved                     */
    .word  PendSV_Handler              /* PendSV Handler               */
    .word  SysTick_Handler             /* SysTick Handler              */

    /* External Interrupts */

    .word  GPIOA_Handler               /* GPIO Port A */
    .word  GPIOB_Handler               /* GPIO Port B */
    .word  GPIOC_Handler               /* GPIO Port C */
    .word  GPIOD_Handler               /* GPIO Port D */
    .word  GPIOE_Handler               /* GPIO Port E */
    .word  UART0_Handler               /* UART0 Rx and Tx */
    .word  UART1_Handler               /* UART1 Rx and Tx */
    .word  SSI0_Handler                /* SSI0 Rx and Tx */
    .word  I2C0_Handler                /* I2C0 Master and Slave */
    .word  PMW0_FAULT_Handler          /* PWM Fault */
    .word  PWM0_0_Handler              /* PWM Generator 0 */
    .word  PWM0_1_Handler              /* PWM Generator 1 */
    .word  PWM0_2_Handler              /* PWM Generator 2 */
    .word  QEI0_Handler                /* Quadrature Encoder 0 */
    .word  ADC0SS0_Handler             /* ADC Sequence 0 */
    .word  ADC0SS1_Handler             /* ADC Sequence 1 */
    .word  ADC0SS2_Handler             /* ADC Sequence 2 */
    .word  ADC0SS3_Handler             /* ADC Sequence 3 */
    .word  WDT0_Handler                /* Watchdog timer */
    .word  TIMER0A_Handler             /* Timer 0 subtimer A */
    .word  TIMER0B_Handler             /* Timer 0 subtimer B */
    .word  TIMER1A_Handler             /* Timer 1 subtimer A */
    .word  TIMER1B_Handler             /* Timer 1 subtimer B */
    .word  TIMER2A_Handler             /* Timer 2 subtimer A */
    .word  TIMER2B_Handler             /* Timer 2 subtimer B */
    .word  COMP0_Handler               /* Analog Comparator 0 */
    .word  COMP1_Handler               /* Analog Comparator 1 */
    .word  COMP2_Handler               /* Analog Comparator 2 */
    .word  SYSCTL_Handler              /* System Control (PLL, OSC, BO) */
    .word  FLASH_Handler               /* FLASH Control */
    .word  GPIOF_Handler               /* GPIO Port F */
    .word  GPIOG_Handler               /* GPIO Port G */
    .word  GPIOH_Handler               /* GPIO Port H */
    .word  UART2_Handler               /* UART2 Rx and Tx */
    .word  SSI1_Handler                /* SSI1 Rx and Tx */
    .word  TIMER3A_Handler             /* Timer 3 subtimer A */
    .word  TIMER3B_Handler             /* Timer 3 subtimer B */
    .word  I2C1_Handler                /* I2C1 Master and Slave */
    .word  QEI1_Handler                /* Quadrature Encoder 1 */
    .word  CAN0_Handler                /* CAN0 */
    .word  CAN1_Handler                /* CAN1 */
    .word  CAN2_Handler                /* CAN2 */
    .word  ETH0_Handler                /* Ethernet */
    .word  HIB_Handler                 /* Hibernate */
    .word  USB0_Handler                /* USB0 */
    .word  PWM0_3_Handler              /* PWM Generator 3 */
    .word  UDMA_Handler                /* uDMA Software Transfer */
    .word  UDMAERR_Handler             /* uDMA Error */
    .word  ADC1SS0_Handler             /* ADC1 Sequence 0 */
    .word  ADC1SS1_Handler             /* ADC1 Sequence 1 */
    .word  ADC1SS2_Handler             /* ADC1 Sequence 2 */
    .word  ADC1SS3_Handler             /* ADC1 Sequence 3 */
    .word  I2S0_Handler                /* I2S0 */
    .word  EPI0_Handler                /* External Bus Interface 0 */
    .word  GPIOJ_Handler               /* GPIO Port J */

    .word  GPIOK_Handler               /* GPIO Port K */
    .word  GPIOL_Handler               /* GPIO Port L */
    .word  SSI2_Handler                /* SSI2 Rx and Tx */
    .word  SSI3_Handler                /* SSI3 Rx and Tx */
    .word  UART3_Handler               /* UART3 Rx and Tx */
    .word  UART4_Handler               /* UART4 Rx and Tx */
    .word  UART5_Handler               /* UART5 Rx and Tx */
    .word  UART6_Handler               /* UART6 Rx and Tx */
    .word  UART7_Handler               /* UART7 Rx and Tx */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  I2C2_Handler                /* I2C2 Master and Slave */
    .word  I2C3_Handler                /* I2C3 Master and Slave */
    .word  TIMER4A_Handler             /* Timer 4 subtimer A */
    .word  TIMER4B_Handler             /* Timer 4 subtimer B */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  0                           /* Reserved */
    .word  TIMER5A_Handler             /* Timer 5 subtimer A */
    .word  TIMER5B_Handler             /* Timer 5 subtimer B */
    .word  WTIMER0A_Handler            /* Wide Timer 0 subtimer A */
    .word  WTIMER0B_Handler            /* Wide Timer 0 subtimer B */
    .word  WTIMER1A_Handler            /* Wide Timer 1 subtimer A */
    .word  WTIMER1B_Handler            /* Wide Timer 1 subtimer B */
    .word  WTIMER2A_Handler            /* Wide Timer 2 subtimer A */
    .word  WTIMER2B_Handler            /* Wide Timer 2 subtimer B */
    .word  WTIMER3A_Handler            /* Wide Timer 3 subtimer A */
    .word  WTIMER3B_Handler            /* Wide Timer 3 subtimer B */
    .word  WTIMER4A_Handler            /* Wide Timer 4 subtimer A */
    .word  WTIMER4B_Handler            /* Wide Timer 4 subtimer B */
    .word  WTIMER5A_Handler            /* Wide Timer 5 subtimer A */
    .word  WTIMER5B_Handler            /* Wide Timer 5 subtimer B */
    .word  FPU_Handler                 /* FPU */
    .word  PECI0_Handler               /* PECI 0 */
    .word  LPC0_Handler                /* LPC 0 */
    .word  I2C4_Handler                /* I2C4 Master and Slave */
    .word  I2C5_Handler                /* I2C5 Master and Slave */
    .word  GPIOM_Handler               /* GPIO Port M */
    .word  GPION_Handler               /* GPIO Port N */
    .word  QEI2_Handler                /* Quadrature Encoder 2 */
    .word  FAN0_Handler                /* Fan 0 */
    .word  0                           /* Reserved */
    .word  GPIOP0_Handler              /* GPIO Port P (Summary or P0) */
    .word  GPIOP1_Handler              /* GPIO Port P1 */
    .word  GPIOP2_Handler              /* GPIO Port P2 */
    .word  GPIOP3_Handler              /* GPIO Port P3 */
    .word  GPIOP4_Handler              /* GPIO Port P4 */
    .word  GPIOP5_Handler              /* GPIO Port P5 */
    .word  GPIOP6_Handler              /* GPIO Port P6 */
    .word  GPIOP7_Handler              /* GPIO Port P7 */
    .word  GPIOQ0_Handler              /* GPIO Port Q (Summary or Q0) */
    .word  GPIOQ1_Handler              /* GPIO Port Q1 */
    .word  GPIOQ2_Handler              /* GPIO Port Q2 */
    .word  GPIOQ3_Handler              /* GPIO Port Q3 */
    .word  GPIOQ4_Handler              /* GPIO Port Q4 */
    .word  GPIOQ5_Handler              /* GPIO Port Q5 */
    .word  GPIOQ6_Handler              /* GPIO Port Q6 */
    .word  GPIOQ7_Handler              /* GPIO Port Q7 */
    .word  GPIOR_Handler               /* GPIO Port R */
    .word  GPIOS_Handler               /* GPIO Port S */
    .word  PMW1_0_Handler              /* PWM 1 Generator 0 */
    .word  PWM1_1_Handler              /* PWM 1 Generator 1 */
    .word  PWM1_2_Handler              /* PWM 1 Generator 2 */
    .word  PWM1_3_Handler              /* PWM 1 Generator 3 */
    .word  PWM1_FAULT_Handler          /* PWM 1 Fault */


/* Exception Handlers */
    .weak   NMI_Handler
    .type   NMI_Handler, %function
NMI_Handler:
    B       .
    .size   NMI_Handler, . - NMI_Handler

    .weak   HardFault_Handler
    .type   HardFault_Handler, %function
HardFault_Handler:
    B       .
    .size   HardFault_Handler, . - HardFault_Handler

    .weak   MemManage_Handler
    .type   MemManage_Handler, %function
MemManage_Handler:
    B       .
    .size   MemManage_Handler, . - MemManage_Handler

    .weak   BusFault_Handler
    .type   BusFault_Handler, %function
BusFault_Handler:
    B       .
    .size   BusFault_Handler, . - BusFault_Handler

    .weak   UsageFault_Handler
    .type   UsageFault_Handler, %function
UsageFault_Handler:
    B       .
    .size   UsageFault_Handler, . - UsageFault_Handler

    .weak   SVC_Handler
    .type   SVC_Handler, %function
SVC_Handler:
    B       .
    .size   SVC_Handler, . - SVC_Handler

    .weak   DebugMon_Handler
    .type   DebugMon_Handler, %function
DebugMon_Handler:
    B       .
    .size   DebugMon_Handler, . - DebugMon_Handler

    .weak   PendSV_Handler
    .type   PendSV_Handler, %function
PendSV_Handler:
    B       .
    .size   PendSV_Handler, . - PendSV_Handler

    .weak   SysTick_Handler
    .type   SysTick_Handler, %function
SysTick_Handler:
    B       .
    .size   SysTick_Handler, . - SysTick_Handler


/* IRQ Handlers */

    .macro  IRQ handler
    .weak   \handler
    .set    \handler, Default_Handler
    .endm

    IRQ     GPIOA_Handler
    IRQ     GPIOB_Handler
    IRQ     GPIOC_Handler
    IRQ     GPIOD_Handler
    IRQ     GPIOE_Handler
    IRQ     UART0_Handler
    IRQ     UART1_Handler
    IRQ     SSI0_Handler
    IRQ     I2C0_Handler
    IRQ     PMW0_FAULT_Handler
    IRQ     PWM0_0_Handler
    IRQ     PWM0_1_Handler
    IRQ     PWM0_2_Handler
    IRQ     QEI0_Handler
    IRQ     ADC0SS0_Handler
    IRQ     ADC0SS1_Handler
    IRQ     ADC0SS2_Handler
    IRQ     ADC0SS3_Handler
    IRQ     WDT0_Handler
    IRQ     TIMER0A_Handler
    IRQ     TIMER0B_Handler
    IRQ     TIMER1A_Handler
    IRQ     TIMER1B_Handler
    IRQ     TIMER2A_Handler
    IRQ     TIMER2B_Handler
    IRQ     COMP0_Handler
    IRQ     COMP1_Handler
    IRQ     COMP2_Handler
    IRQ     SYSCTL_Handler
    IRQ     FLASH_Handler
    IRQ     GPIOF_Handler
    IRQ     GPIOG_Handler
    IRQ     GPIOH_Handler
    IRQ     UART2_Handler
    IRQ     SSI1_Handler
    IRQ     TIMER3A_Handler
    IRQ     TIMER3B_Handler
    IRQ     I2C1_Handler
    IRQ     QEI1_Handler
    IRQ     CAN0_Handler
    IRQ     CAN1_Handler
    IRQ     CAN2_Handler
    IRQ     ETH0_Handler
    IRQ     HIB_Handler
    IRQ     USB0_Handler
    IRQ     PWM0_3_Handler
    IRQ     UDMA_Handler
    IRQ     UDMAERR_Handler
    IRQ     ADC1SS0_Handler
    IRQ     ADC1SS1_Handler
    IRQ     ADC1SS2_Handler
    IRQ     ADC1SS3_Handler
    IRQ     I2S0_Handler
    IRQ     EPI0_Handler
    IRQ     GPIOJ_Handler

    IRQ     GPIOK_Handler
    IRQ     GPIOL_Handler
    IRQ     SSI2_Handler
    IRQ     SSI3_Handler
    IRQ     UART3_Handler
    IRQ     UART4_Handler
    IRQ     UART5_Handler
    IRQ     UART6_Handler
    IRQ     UART7_Handler
    IRQ     I2C2_Handler
    IRQ     I2C3_Handler
    IRQ     TIMER4A_Handler
    IRQ     TIMER4B_Handler
    IRQ     TIMER5A_Handler
    IRQ     TIMER5B_Handler
    IRQ     WTIMER0A_Handler
    IRQ     WTIMER0B_Handler
    IRQ     WTIMER1A_Handler
    IRQ     WTIMER1B_Handler
    IRQ     WTIMER2A_Handler
    IRQ     WTIMER2B_Handler
    IRQ     WTIMER3A_Handler
    IRQ     WTIMER3B_Handler
    IRQ     WTIMER4A_Handler
    IRQ     WTIMER4B_Handler
    IRQ     WTIMER5A_Handler
    IRQ     WTIMER5B_Handler
    IRQ     FPU_Handler
    IRQ     PECI0_Handler
    IRQ     LPC0_Handler
    IRQ     I2C4_Handler
    IRQ     I2C5_Handler
    IRQ     GPIOM_Handler
    IRQ     GPION_Handler
    IRQ     QEI2_Handler
    IRQ     FAN0_Handler
    IRQ     GPIOP0_Handler
    IRQ     GPIOP1_Handler
    IRQ     GPIOP2_Handler
    IRQ     GPIOP3_Handler
    IRQ     GPIOP4_Handler
    IRQ     GPIOP5_Handler
    IRQ     GPIOP6_Handler
    IRQ     GPIOP7_Handler
    IRQ     GPIOQ0_Handler
    IRQ     GPIOQ1_Handler
    IRQ     GPIOQ2_Handler
    IRQ     GPIOQ3_Handler
    IRQ     GPIOQ4_Handler
    IRQ     GPIOQ5_Handler
    IRQ     GPIOQ6_Handler
    IRQ     GPIOQ7_Handler
    IRQ     GPIOR_Handler
    IRQ     GPIOS_Handler
    IRQ     PMW1_0_Handler
    IRQ     PWM1_1_Handler
    IRQ     PWM1_2_Handler
    IRQ     PWM1_3_Handler
    IRQ     PWM1_FAULT_Handler

    .end

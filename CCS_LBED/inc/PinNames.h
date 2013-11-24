/* mbed Microcontroller Library - PinNames
 * Copyright (C) 2008-2009 ARM Limited. All rights reserved.
 *
 * Provides the mapping of mbed DIP and LPC Pin Names
 * This is an LPC1768/LPC2368 specific implementation
 * sford
 */

#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#ifdef __cplusplus
extern "C" {
#endif

//typedef enum PinName PinName;
typedef int PinName;
enum e_PinName {
    // Not connected
        NC = (int)0xFFFFFFFF
    // GPIOPORT definition
	  ,  PA_0 = 0, PA_1, PA_2, PA_3, PA_4, PA_5, PA_6, PA_7
	  , PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7
	  , PC_0, PC_1, PC_2, PC_3, PC_4, PC_5, PC_6, PC_7
	  , PD_0, PD_1, PD_2, PD_3, PD_4, PD_5, PD_6, PD_7
	  , PE_0, PE_1, PE_2, PE_3, PE_4, PE_5
	  , PF_0, PF_1, PF_2, PF_3, PF_4
    // mbed DIP Pin Names
      , J1_1 = NC
      , J1_2 = PB_5
      , J1_3 = PB_0
      , J1_4 = PB_1
      , J1_5 = PE_4
      , J1_6 = PE_5
      , J1_7 = PB_4
      , J1_8 = PA_5
      , J1_9 = PA_6
      , J1_10 = PA_7
      , J3_1 = NC
      , J3_2 = NC
      , J3_3 = PD_0
      , J3_4 = PD_1
      , J3_5 = PD_2
      , J3_6 = PD_3
      , J3_7 = PE_1
      , J3_8 = PE_2
      , J3_9 = PE_3
      , J3_10 = PF_1
      , J4_1 = PF_2
      , J4_2 = PF_3
      , J4_3 = PB_3
      , J4_4 = PC_4
      , J4_5 = PC_5
      , J4_6 = PC_6
      , J4_7 = PC_7
      , J4_8 = PD_6
      , J4_9 = PD_7
      , J4_10 = PF_4
      , J2_1 = NC
      , J2_2 = PB_2
      , J2_3 = PE_0
      , J2_4 = PF_0
      , J2_5 = NC // RST
      , J2_6 = PB_7
      , J2_7 = PB_6
      , J2_8 = PA_4
      , J2_9 = PA_3
      , J2_10 = PA_2
      , USBRX = PA_0
      , USBTX = PA_1
      , SCL = PB_2
      , SDA = PB_3
      , LEDR = J3_10
      , LEDB = J4_1
      , LEDG = J4_2
      , SW2 = J2_4
      , SW1 = J4_10
      , A0 = PE_3
      , A1 = PE_2
      , A2 = PE_1
      , A3 = PE_0
      , A4 = PD_3
      , A5 = PD_2
      , A6 = PD_1
      , A7 = PD_0
      , A8 = PE_5
      , A9 = PE_4
      , A10 = PB_4
      , A11 = PD_5
      , T1CCP1 = PB_5
      , T2CCP0 = PB_0
      , T2CCP1 = PB_1
      , T1CCP0 = PB_4
      , T3CCP0 = PB_2
      , T0CCP1 = PB_7
      , T0CCP0 = PB_6
      , T3CCP1 = PB_3
      , PWM0 = PB_5
      , PWM1 = PB_0
      , PWM2 = PB_1
      , PWM3 = PB_4
      , PWM4 = PB_2
      , PWM5 = PB_7
      , PWM6 = PB_6
      , PWM7 = PB_3

};

//typedef enum PinMode PinMode;
typedef int PinMode;
enum e_PinMode {
    PullUp = 0
    , PullDown = 3
    , PullNone = 2
    , OpenDrain = 4
};

#ifdef __cplusplus
}
#endif

#endif 

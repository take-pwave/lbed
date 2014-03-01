#ifndef	LBED_H
#define	LBED_H

#define	NC	(-1)
typedef char PinName;

#include "DigitalOut.h"
#include "DigitalIn.h"
#include "I2C.h"
#include "wait_api.h"
#include "Print.h"

extern "C" {
extern void lbed_setup();
extern void I2C_SwitchMatrix_Init();
}

// ビン番号を定義
#define	P1	5
#define	P2	4
#define	P3	3
#define	P4	2
#define	P5	1
#define	P8	0
#define	SDA	0
#define	SCL	4

#endif	/* LBED_H */

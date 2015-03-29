#ifndef	LBED_H
#define	LBED_H
#include "Arduino.h"

#define	NC	(-1)
typedef int PinName;

#define wait_ms(ms) delay(ms)
#define wait_us(us) delayMicroseconds(us)

#define	D0	0
#define	D1	1
#define	D2	2
#define D3	3
#define	D4	4
#define	D5	5
#define	D6	6
#define	D7	7
#define	D8	8
#define	D9	9
#define	D10	10
#define	D11	11
#define	D12	12
#define	D13	13

#define	PullUp	INPUT_PULLUP

#include "utility/DigitalOut.h"
#include "utility/DigitalIn.h"
#include "utility/AnalogIn.h"
#include "utility/BusOut.h"
#include "utility/Tone.h"
#include "utility/PwmOut.h"
#include "utility/I2C.h"
#endif

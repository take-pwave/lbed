#ifndef	LBED_H
#define	LBED_H
#include "Arduino.h"

#define	NC	(-1)
typedef int PinName;

#define wait_ms(ms) delay(ms)
#define wait_us(us) delayMicroseconds(us)

#include "utility/DigitalOut.h"
#include "utility/DigitalIn.h"
#include "utility/AnalogIn.h"
#include "utility/BusOut.h"
#include "utility/Tone.h"
#include "utility/PwmOut.h"
#include "utility/I2C.h"
#endif
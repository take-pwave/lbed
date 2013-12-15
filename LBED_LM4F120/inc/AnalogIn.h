#ifndef LBED_ANALOGIN_H
#define LBED_ANALOGIN_H

#include "platform.h"
#include "PinNames.h"
#include "DigitalIn.h"

class AnalogIn {

public:

	/* Constructor: AnalogIn
	 *  Create an AnalogIn , connected to the specified pin.
	 *
	 * Variables:
	 *  pin - AnalogIn pin to connect to
	 */
	AnalogIn();
	AnalogIn(PinName pin, const char* name = 0);
	void setup(PinName pin, const char* name = 0);

	/* Function: read
	 * Read the input voltage, represented as a float in the range [0.0, 1.0].
	 */
	float read();

	/* Function: operator float()
	 *  An operator shorthand for read()
	 */
	operator float()
	{
		return read();
	}

	/* Function: read
	 * Read the input voltage, represented as an unsigned short in the range [0x0, 0xFFFF].
	 */
	unsigned short read_u16();


protected:
	short			_pin;
	short			_channel;
	int				_gpio;
	unsigned long 	_value;
	static uint32_t	_b_mask;
	static uint32_t	_d_mask;
	static uint32_t	_e_mask;
};

#endif


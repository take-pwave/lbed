#ifndef LBED_DIGITALOUT_H
#define LBED_DIGITALOUT_H

#include "platform.h"
#include "PinNames.h"
#include "DigitalIn.h"

class DigitalOut : public DigitalIn {

public:

	/* Constructor: DigitalOut
	 *  Create a DigitalOut connected to the specified pin
	 *
	 * Variables:
	 *  pin - DigitalOut pin to connect to
	 */
	DigitalOut();
	DigitalOut(PinName pin, const char* name = 0);
	void setup(PinName pin, const char* name = 0);

	/* Function: write
	 *  Set the output, specified as 0 or 1 (int)
	 *
	 * Variables:
	 *  value - An integer specifying the pin output value,
	 *      0 for logical 0 and 1 (or any other non-zero value) for logical 1
	 */
	void write(int value)
	{
		if (_gpio) {
			if (value) {
				_gpio->DATA |= _mask;
			} else {
				_gpio->DATA &= ~ _mask;
			}
		}
	}

	/* Function: operator=
	 *  A shorthand for <write>
	 */
	DigitalOut& operator = (int value)
	{
		write(value);
		return *this;
	}

	DigitalOut& operator = (DigitalOut& rhs)
	{
		write(rhs.read());
		return *this;
	}

};

#endif


#ifndef LBED_DIGITALIN_H
#define LBED_DIGITALIN_H

#include "platform.h"
#include "PinNames.h"

class DigitalIn {

public:

	/* Constructor: DigitalIn
	 * Create a DigitalIn connected to the specified pin.
	 *
	 * Parameters:
	 * pin	DigitalIn pin to connect to
	 * name	(optional) A string to identify the object
	 */
	DigitalIn();
	DigitalIn(PinName pin, const char* name = 0);
	void setup(PinName pin, const char* name = 0);


	/* Function: read
	 * Read the input, represented as 0 or 1 (int)
	 *
	 * Returns:
	 * An integer representing the state of the input pin, 0 for logical 0, 1 for logical 1
	 *
	 */
	int read();

	/* Function: operator int()
	 *  An operator shorthand for read()
	 */
	operator int()
	{
		return read();
	}

	/*
	 * Set the input pin mode.
	 * Parameters:
	 * mode	PullUp, PullDown, PullNone, OpenDrain
	 */
	void mode(PinMode pull);

protected:

	PinName             _pin;
	GPIOA_Type    		*_gpio;
	uint32_t            _mask;
};
#endif


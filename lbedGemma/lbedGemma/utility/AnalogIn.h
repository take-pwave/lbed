#ifndef LBED_ANALOGIN_H
#define LBED_ANALOGIN_H

class AnalogIn {
public:
	AnalogIn();
	AnalogIn(int pin);
	void _setup(int pin);

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
	 * Read the input voltage, represented as an unsigned short in the range [0, 1023].
	 */
	unsigned short read_u16();
protected:
	short	_pin;
};

#endif

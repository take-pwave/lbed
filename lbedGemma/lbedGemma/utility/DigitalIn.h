#ifndef LBED_DIGITALIN_H
#define LBED_DIGITALIN_H

class DigitalIn {
public:
	DigitalIn();
	DigitalIn(int pin);
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
	 * mode	INPUT, INPUT_PULLUP
	 */
	void mode(int pull);
protected:
	void _setup(int pin);
	int             _pin;
};
#endif

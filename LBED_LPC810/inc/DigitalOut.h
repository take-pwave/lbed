#ifndef	LBED_DIGITALOUT_H
#define	LBED_DIGITALOUT_H

class DigitalOut {
public:
    DigitalOut();
    DigitalOut(char pin);
    void    write(char value);
    void    setup(char pin);
	/* Function: operator int()
	 *  An operator shorthand for read()
	 */
	operator int()
	{
		return read();
	}
	/* Function: operator=
	 *  A shorthand for <write>
	 */
	DigitalOut& operator = (int value)
	{
        _value = value;
		write(value);
		return *this;
	}

	DigitalOut& operator = (DigitalOut& rhs)
	{
		write(rhs.read());
		return *this;
	}
	char read(void)
	{
	    return _value;
	}
private:
	char     	_value;
protected:
    char     	_pin;
};
#endif	/* LBED_DIGITALOUT_H */

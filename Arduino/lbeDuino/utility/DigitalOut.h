#ifndef	LBED_DIGITALOUT_H
#define	LBED_DIGITALOUT_H

class DigitalOut {
public:
    DigitalOut();
    DigitalOut(int pin);
    void    write(int value);
    int     read(void);
    void    _setup(int pin);
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
private:
    int     _value;
protected:
    int     _pin;
};
#endif	/* LBED_DIGITALOUT_H */
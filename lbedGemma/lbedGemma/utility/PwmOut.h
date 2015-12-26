#ifndef LBED_PWMOUT_H
#define LBED_PWMOUT_H

class PwmOut {
public:
	PwmOut(int pin);
	/* Arduino PWM is 490Hz or 980Hz only. */
	void period(float seconds) {
		// do nothing 
	}
    void pulsewidth(float seconds) {
        // do nothing
    }
	void write(float value);
	/*
	 * Return the current output duty-cycle setting, measured as a percentage (float)
	 */
	float read() {
		return _value;
	}
    
	PwmOut& operator = (float value)
	{
		write(value);
		return *this;
	}
    
	operator float()
	{
		return read();
	}
    
	void disable(void);
protected:
    int     _pin;
    float   _value;
};

#endif

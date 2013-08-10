#ifndef LBED_PWMOUT_H
#define LBED_PWMOUT_H

#include <PinNames.h>

#include "type.h"
#include "_timer16.h"
#include "_timer32.h"
#include "_gpio.h"


/* Class: PwmOut
 *  The PwmOut interface is used to control the frequency and mark-space ratio
 *  of a digital pulse train.
 *
 * The hardware has 6 PWM channels, and the PwmOut Interface can be used on mbed pins p21-p26.
 *
 * The default period is 0.020s, and the default pulsewidth is 0.
 *
 * The PwmOut interface can express the pulse train in many ways depening on how it is to be used.
 * The period and pulse width can be expressed directly in units of seconds, millisecond or
 * microseconds. The pulsewidth can also be expressed as a percentage of the the period.
 */ 
class PwmOut {

public:
    /*
     * Create a PwmOut connected to the specified pin.
     * Parameters:
     * pin	PwmOut pin to connect to
     * Definition at line 61 of file PwmOut.h.
     */
	PwmOut(PinName pin);

	/*
	 * Set the PWM period, specified in seconds (float), keeping the duty cycle the same.
	 */
	void period(float seconds);

	/*
	 * Set the PWM pulsewidth, specified in seconds (float), keeping the period the same.
	 */
	void pulsewidth(float seconds);

	/*
	 * Set the ouput duty-cycle, specified as a percentage (float)
	 *
	 * Returns:
	 * A floating-point value representing the current duty-cycle being output on the pin, measured as a percentage.
	 * The returned value will lie between 0.0f (representing on 0%) and 1.0f (representing on 100%).
	 */
	void write(float value) {
		_value = value;
		_pulsewidth = _period*_value;
		pulsewidth(_pulsewidth);
	}

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
    const char *    _name;
	PinName 		_pin;
	float			_period;
	float			_pulsewidth;
	float			_value;
	uint32_t		_scale;	// prescle factor init_timer16PWMのperiodがSysclock/1000を超えたときに1000にする。デフォルト1

private:
	void setup(float seconds);
};

#endif


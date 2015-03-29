#include "Arduino.h"
#include "lbed.h"

PwmOut::PwmOut(int pin)
	: _pin(NC), _value(0.0)
{
	if (pin != NC){
		_pin = pin;
	}
}

void PwmOut::write(float value)
{
    _value = value;
    // 変な値がセットされないように予防
    if (value > 1.0)	value = 1.0;
    else if (value < 0)	value = 0.0;
    // ArduinoのPWMは、0~255
    analogWrite(_pin, (int)(value*255));
}
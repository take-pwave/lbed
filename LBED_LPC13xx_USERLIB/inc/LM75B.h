#ifndef LM75B_H
#define LM75B_H

#include "lbed.h"

//  LM75B IIC address
#define    LM75_ADDR (0x49 << 1)

class LM75B
{
public:
  //!Creates an instance of the class.
  /*!
  Connect module at I2C address addr using I2C port pins sda and scl.
  LM75B
  */
	LM75B(PinName sda, PinName scl);
  
  /*!
  Destroys instance.
  */ 
  ~LM75B();
  
  //!Reads the current temperature.
  /*!
  Reads the temperature register of the LM75B and converts it to a useable value.
  */
  float read();

  I2C i2c;
  
private:
  

};

#endif

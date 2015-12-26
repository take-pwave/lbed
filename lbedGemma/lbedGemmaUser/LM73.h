#ifndef LM73_H
#define LM73_H

#include "lbed.h"

//  LM73 IIC address
#define    LM73_ADDR (0x4C << 1)

class LM73
{
public:
    LM73(){}
  //!Creates an instance of the class.
  /*!
  Connect module at I2C address addr using I2C port pins sda and scl.
  LM73
  */
  LM73(PinName sda, PinName scl);
  
  /*!
  Destroys instance.
  */ 
  ~LM73();
  
  //!Reads the current temperature.
  /*!
  Reads the temperature register of the LM73 and converts it to a useable value.
  */
  float read();
  /* Arduino 固有のメソッド */
  void setup();
  
private:
    I2C i2c;  

};

#endif

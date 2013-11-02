#include "I2cLCD.h"
#include "lbed.h"

#define    I2CLCD_ADDR    0x7C

#define RS_CMD        0x00
#define RS_DATA       0x40

#define FUNC_SET1    0x38
#define FUNC_SET2    0x39
#define INT_OSC      0x14

#define CNTR_DEF    0x20

unsigned char icon_data[]=
{
    0x00, 0x10,
    0x02, 0x10,
    0x04, 0x10,
    0x06, 0x10,

    0x07, 0x10,
    0x07, 0x08,
    0x09, 0x10,
    0x0B, 0x10,

    0x0D, 0x08,
    0x0D, 0x04,
    0x0D, 0x02,
    0x0D, 0x10,

    0x0F, 0x10,
};

I2cLCD::I2cLCD(PinName sda, PinName scl, PinName rp) :  _rs( rp ) , _i2c( sda , scl ){

    contrast = CNTR_DEF;
    icon = 0;

    wait(0.015);
    // reset LOW->HIGH
    _rs = 0;
    wait(0.01);
    _rs = 1;
    wait(0.05);

    writeCommand(FUNC_SET1);
    writeCommand(FUNC_SET2);
    writeCommand(INT_OSC);

    writeCommand(0x70 | (contrast & 0xF));
    writeCommand(0x5C | ((contrast >> 4) & 0x3));

    writeCommand(0x6C);
    wait(0.3);

    writeCommand(0x38); // function set
    writeCommand(0x0C); // Display On

    cls(); // Clear Display

}



void I2cLCD::character(int column, int row, int c) {
    int a = address(column, row);
    writeCommand(a);
    writeData(c);
}

void I2cLCD::cls() {
    writeCommand(0x01); // cls, and set cursor to 0
    wait(0.00164f);     // This command takes 1.64 ms
    locate(0, 0);
}

void I2cLCD::locate(int column, int row) {
    _column = column;
    _row = row;
}

int I2cLCD::_putc(int value) {
    if (value == '\n') {
        _column = 0;
        _row++;
        if (_row >= rows()) {
            _row = 0;
        }
    } else {
        character(_column, _row, value);
        _column++;
        if (_column >= columns()) {
            _column = 0;
            _row++;
            if (_row >= rows()) {
                _row = 0;
            }
        }
    }
    return value;
}

int I2cLCD::_getc() {
    return -1;
}

void I2cLCD::writeCommand( int cmd )
{
    char cmds[2];

    cmds[0] = RS_CMD;
    cmds[1] = cmd;

    _i2c.write(I2CLCD_ADDR, cmds, 2);
}

void I2cLCD::writeData( int data )
{
    char cmd[2];

    cmd[0] = RS_DATA;
    cmd[1] = data;

    _i2c.write(I2CLCD_ADDR, cmd, 2);
}

int I2cLCD::address(int column, int row) {

    return 0x80 + (row * 0x40) + column;
}

int I2cLCD::columns() {
    return 16;
}

int I2cLCD::rows() {
    return 2;
}

void I2cLCD::seticon(IconType type)
{
    icon |= type;
    puticon( icon );
}

void I2cLCD::clearicon(IconType type)
{
    icon &= ~type;
    puticon( icon );
}


void I2cLCD::puticon(int flg)
{
    static unsigned char icon_buff[16];
    unsigned char i;

    for(i=0;i<sizeof(icon_data)/2;i++)
    {
        if(flg & (0x1000>>i))
        {
            icon_buff[icon_data[i*2]] |= icon_data[i*2+1];
        }
        else
        {
            icon_buff[icon_data[i*2]] &= ~icon_data[i*2+1];
        }
    }

    for(i=0;i<16;i++){
        writeCommand(0x39);
        writeCommand(0x40+i);
        writeData(icon_buff[i]);
    }
}


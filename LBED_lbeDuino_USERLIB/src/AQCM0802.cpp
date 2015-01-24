#include "AQCM0802.h"
#include "lbed.h"

#define I2CLCD_ADDR   0x7C

#define RS_CMD        0x00
#define RS_DATA       0x40

#define FUNC_SET1     0x38
#define FUNC_SET2     0x39
#define INT_OSC       0x14

#define CNTR_DEF      0x20

AQCM0802::AQCM0802(PinName sda, PinName scl) :  _i2c(sda , scl) {
	//AQCM0802::setup();
}

void AQCM0802::setup() {
    contrast = CNTR_DEF;

    wait_ms(40);

    writeCommand(FUNC_SET1);
    writeCommand(FUNC_SET2);
    writeCommand(INT_OSC);

    writeCommand(0x70 | (contrast & 0xF));
    writeCommand(0x5C | ((contrast >> 4) & 0x3));

    writeCommand(0x6C);
    wait_ms(300); //wait(0.3);

    writeCommand(0x38); // function set
    writeCommand(0x0C); // Display On

    cls(); // Clear Display
}

void AQCM0802::character(int column, int row, int c) {
    int a = address(column, row);
    writeCommand(a);
    writeData(c);
}

void AQCM0802::cls() {
    writeCommand(0x01); // cls, and set cursor to 0
    wait_ms(1); wait_us(640); //wait(0.00164f);     // This command takes 1.64 ms
    locate(0, 0);
}

void AQCM0802::locate(int column, int row) {
    _column = column;
    _row = row;
}

int AQCM0802::_putc(int value) {
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

int AQCM0802::_getc() {
    return -1;
}

void AQCM0802::writeCommand( int cmd )
{
    char cmds[2];

    cmds[0] = RS_CMD;
    cmds[1] = cmd;

    _i2c.write(I2CLCD_ADDR, cmds, 2);
}

void AQCM0802::writeData( int data )
{
    char cmd[2];

    cmd[0] = RS_DATA;
    cmd[1] = data;

    _i2c.write(I2CLCD_ADDR, cmd, 2);
}

int AQCM0802::address(int column, int row) {

    return 0x80 + (row * 0x40) + column;
}

int AQCM0802::columns() {
    return 16;
}

int AQCM0802::rows() {
    return 2;
}

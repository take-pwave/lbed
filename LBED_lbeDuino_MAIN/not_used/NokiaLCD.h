/* mbed NokiaLCD Library, for a 130x130 Nokia colour LCD
 * Copyright (c) 2007-2010, sford
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MBED_NOKIALCD_H
#define MBED_NOKIALCD_H

#include "lbed.h"

/** An interface for the 130x130 Nokia Mobile phone screens
 *
 * @code
 * #include "mbed.h"
 * #include "NokiaLCD.h"
 *
 * NokiaLCD lcd(p5, p7, p8, p9, NokiaLCD::6610); // mosi, sclk, cs, rst, type
 *
 * int main() {
 *     lcd.printf("Hello World!");
 * }
 * @endcode
 */
class NokiaLCD : public Print {

public:
    /** LCD panel format */
    enum LCDType {
        LCD6100     /**< Nokia 6100, as found on sparkfun board (default) */
        , LCD6610   /**< Nokia 6610, as found on olimex board */
        , PCF8833
    };

    /** Create and Nokia LCD interface, using a SPI and two DigitalOut interfaces
     *
     * @param mosi SPI data out
     * @param sclk SPI clock
     * @param cs Chip Select (DigitalOut)
     * @param rst Reset (DigitalOut)
     * @param type The LCDType to select driver chip variants
     */
    NokiaLCD(PinName mosi, PinName sclk, PinName cs, PinName rst, LCDType type = LCD6100);

#if DOXYGEN_ONLY
    /** Write a character to the LCD
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** Write a formated string to the LCD
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formating the string.
     */
    int printf(const char* format, ...);
#endif
    
    /** Locate to a screen column and row
     *
     * @param column  The horizontal position from the left, indexed from 0
     * @param row     The vertical position from the top, indexed from 0
     */
    void locate(int column, int row);

    /** Clear the screen and locate to 0,0 */
    void cls();

    /** Set a pixel on te screen
     * 
     * @param x horizontal position from left
     * @param y vertical position from top
     * @param colour 24-bit colour in format 0x00RRGGBB
     */
    void pixel(int x, int y, int colour);
    
    /** Fill an area of the screen
     * 
     * @param x horizontal position from left
     * @param y vertical position from top
     * @param width width in pixels
     * @param height height in pixels
     * @param colour 24-bit colour in format 0x00RRGGBB
     */    
    void fill(int x, int y, int width, int height, int colour);

    void blit(int x, int y, int width, int height, const int* colour);
    void bitblit(int x, int y, int width, int height, const char* bitstream);

    int width();
    int height();
    int columns();
    int rows();

    void reset();

    /** Set the foreground colour
     * 
     * @param c 24-bit colour
     */
    void foreground(int c);

    /** Set the background colour
     * 
     * @param c 24-bit colour
     */
    void background(int c);

protected:
    /*virtual*/ void _window(int x, int y, int width, int height);
    /*virtual*/ void _putp(int colour);

    void command(int value);
    void data(int value);

    void newline();
    virtual int _putc(int c);
    virtual int write(const char c) {
    	return _putc(c);
    }
    virtual int _getc() {
        return 0;
    }
    void putp(int v);
    void window(int x, int y, int width, int height);

    SPI _spi;
    DigitalOut _rst;
    DigitalOut _cs;

    LCDType _type;
    int _row, _column, _rows, _columns, _foreground, _background, _width, _height;
};

#endif



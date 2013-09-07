/** MARMEX_OB OLED screen drawing library
 *
 *  @class   MARMEX_OB_oled
 *  @author  tedd
 *  @version 0.51
 *  @date    08-Apr-2011
 *
 *  Released under the MIT License: http://mbed.org/license/mit
 *
 *  MARMEX_OB_oled OLED screen drawing library for mbed
 *  This code has been written based on sample code and advises
 *    from Ochiai-san (Marutsu-Elec). Thank you!
 *
 *  SPI mode:
 *    9bit or 8bit SPI mode can be selected by disabling/enabling "#define MARMEX_OB_SPI_8BIT_MODE".
 *    See source code in this (MARMEX_OB_oled.h) file.
 */

#ifndef     MBED_MARMEX_OB_OLED
#define     MBED_MARMEX_OB_OLED

#include    "lbed.h"
#include    <math.h>


/** @def MARMEX_OB_SPI_8BIT_MODE
 *
 *  MARMEX_OB_oled_oled OLED screen SPI access length setting
 *  Enabling "MARMEX_OB_SPI_8BIT_MODE" makes 9bit SPI access by 8bit * 2 times.
 *  This may be useful if other 8bit access SPI device on same SPI bus.
 *
 *  If disabled (just coment out the "#define MARMEX_OB_SPI_8BIT_MODE"), SPI access willbe done by 9 bit format.
 */
//#define MARMEX_OB_SPI_8BIT_MODE
#define MARMEX_OB_SPI_8BIT_MODE

/** MARMEX_OB_oled OLED screen drawing class
 *
 *  This is a driver code for MARMEX_OB_oled board OLED screen.
 *  This class inherits NokiaLCD class of mbed.org.
 *  To use this class, import the NokiaLCD class from here..
 *   http://mbed.org/users/simon/libraries/NokiaLCD/
 *
 *  Example:
 *  @code
 *  #include "mbed.h"
 *  #include "MARMEX_OB_oled.h"
 *  
 *  //  oled1 is for MARMEX_OB_oled board on MAPLE slot 1
 *  //  oled1 is for MARMEX_OB_oled board on MAPLE slot 2
 *  
 *  MARMEX_OB_oled   oled1( p5, p7,  p8, p30, p11 ); // mosi, sclk, cs, rst, power_control
 *  //MARMEX_OB_oled   oled2( p5, p7, p26, p21, p17 ); // mosi, sclk, cs, rst, power_control
 *  
 *  
 *  int main() {
 *      oled1.background( 0x000000 );
 *      oled1.cls();
 *     
 *      int colorbar_width  = MARMEX_OB_oled::WIDTH / 8;
 *  
 *      for ( int i = 0; i < 8; i++ )
 *          oled1.fill( colorbar_width * i, 0, colorbar_width, MARMEX_OB_oled::HEIGHT, ((i & 0x4) ? 0xFF0000 : 0x000000) | ((i & 0x2) ? 0x00FF00 : 0x000000) | ((i & 0x1) ? 0x0000FF : 0x000000) );
 *  
 *      oled1.fill(  50,  50,  64,  64, 0xCCCCCC );;
 *  
 *      oled1.locate( 0, 3 );
 *      oled1.printf( "Hello World!" );
 *      oled1.locate( 0, 4 );
 *      oled1.printf( "SPI = %s", MERMEX_OB_SPI_MODE_STR );
 *  
 *      for (int i = 0; i < MARMEX_OB_oled::WIDTH; i++ ) {
 *          oled1.pixel( i, 80 + sin( (float)i / 5.0 ) * 10, 0x000000 );
 *      }
 *  } *  @endcode
 */

class MARMEX_OB_oled /*: Print*/ {

public:

    /** General parameters for MARMEX_OB_oled */
    enum  {
        ROWS          = 15,         /**< # of rows (lines) for displaying characters  */
        COLS          = 16,         /**< # of columns (width) for displaying characters  */
        WIDTH         = 128,        /**< screen width [pixels]  */
        HEIGHT        = 128,        /**< screen height [pixels]  */
        SPI_FREQUENCY = 12000000    /**< SPI (sclk) SPI_FREQUENCY  */
    };

    /** Constants for power() function */
    enum  {
        OFF   = 0,  /**< : to turning-OFF  */
        ON          /**< : to turning-ON   */
    };

    /** Create a MARMEX_OB_oled object connected to specified SPI and DigitalOut pins
     *
     *  @param mosi SPI-MOSI pin (for MAPLE board, use p5)
     *  @param sclk SPI-SCLK pin (for MAPLE board, use p8)
     *  @param cs   chip select signal (for MAPLE board, use p8(slot1), p26(slot2))
     *  @param rst  reset signal (for MAPLE board, use p30(slot1), p21(slot2))
     *  @param power_pin backlight power control signal (for MAPLE board, use p11(slot1), p17(slot2))
     *
     *  Example of MARMEX_OB_oled on MAPLE board:
     *  @code
     *  #include "mbed.h"
     *  #include "MARMEX_OB_oled.h"
     *
     *  MARMEX_OB_oled   oled_on_maple_slot1( p5, p7,  p8, p30, p11 ); // mosi, sclk, cs, rst, power_control
     *  MARMEX_OB_oled   oled_on_maple_slot2( p5, p7, p26, p21, p17 ); // mosi, sclk, cs, rst, power_control
     *  ...
     *  ..
     *  @endcode
     */

    MARMEX_OB_oled( PinName mosi, PinName sclk, PinName cs, PinName rst, PinName power_pin );

#if DOXYGEN_ONLY
    /** Write a character to the LCD
     *
     * @param c The character to write to the display
     */
    int putc( int c );

    /** Write a formated string to the LCD
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formating the string.
     *
     *  !!! 16th character in the string will be disappeared
     *  !!! This problem is due to difference of screen size NokiaLCD library and its internal mechanism...
     */
    int printf( const char* format, ... );

#endif

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

    /** reset MARMEX_OB_oled
     *
     *  Executes hardware reset and initialize.
     *  See MARMEX_OB_oled manual for the initialization sequence and values
     *  For gamma correction table, using math function to make the code simple
     */

    void reset( void ) {

#define GAMMA_LUT_SIZE 63
        unsigned char    gamma_LUT[ GAMMA_LUT_SIZE ];

        for ( int i = 0; i < GAMMA_LUT_SIZE; i++ )
            gamma_LUT[ i ]  = (unsigned char)(powf( ((float)i / 62.0), (1.0 / 0.58) ) * 178.0 + 2.0);

        // setup the SPI interface and bring display out of reset
        _cs = 1;
        _rst = 0;
#ifdef MARMEX_OB_SPI_8BIT_MODE
        _spi.format( 8 );
#else
        _spi.format( 9 );
#endif

        _spi.frequency( SPI_FREQUENCY );
        wait_ms( 1 );
        _rst = 1;
        wait_ms( 1 );

        _cs = 0;

        command( SET_DISPLAY_MODE_ALL_OFF );
        command( SET_COMMAND_LOCK );
        data( 0x12 );

        command( SET_COMMAND_LOCK );
        data( 0xb1 );

        command( SET_SLEEP_MODE_ON );

        command( FRONT_CLOCK_DRIVER_OSC_FREQ );
        data( 0xF1 );

        command( SET_MUX_RATIO );
        data( 0x7F );

        command( SET_DISPAY_OFFSET );
        data( 0x00 );

        command( SET_DISPAY_START_LINE );
        data( 0x00 );

        command( SET_REMAP_COLOR_DEPTH );
        data( 0x74 );

        command( SET_GPIO );
        data( 0x00);

        command( FUNCTION_SELECTION );
        data( 0x01 );

        command( SET_SEGMENT_LOW_VOLTAGE );
        data( 0xA0 );
        data( 0xB5 );
        data( 0x55 );

        command( SET_CONTRAST_CURRENT_FOR_COLOR_ABC );
        data( 0xC8 );
        data( 0x80 );
        data( 0xC8 );

        command( MASTER_CONTRAST_CURRENT_CONTROL );
        data( 0x0F );

        command( LOOKUP_TABLE_FOR_GRAYSCALE_PULSE_WIDTH );
        for ( int i = 0; i < GAMMA_LUT_SIZE; i++ )
            data(  gamma_LUT[ i ] );

        command( SET_RESET_PRECHARGE_PERIOD );
        data( 0x32 );

        command( ENHANCE_DRIVING_SCHEME_CAPABILITY );
        data( 0x04 );
        data( 0x00 );
        data( 0x00 );

        command( SET_PRECHARGE_VOLTAGE );
        data( 0x17 );

        command( SET_SECOND_PRECHARGE_VOLTAGE );
        data( 0x01 );

        command( SET_VCOMH_VOLTAGE );
        data( 0x05 );

        command( SET_DISPLAY_MODE_RESET );

#if 0
        command( SET_COLUMN_ADDRESS );
        data( 0x00 );
        data( 0x7F );

        command( SET_ROW_ADDRESS );
        data( 0x00 );
        data( 0x7F);

        command( WRITE_RAM_COMMAND );
        for ( int i = 0; i < WIDTH * HEIGHT; i++ )
            data( 0x00 );
#endif
        _cs = 1;

        cls();
        wait_ms( 200 );

        command( SET_SLEEP_MODE_OFF );
    }

    /** Clear the screen and locate to 0,0 */

    void cls( void ) {
        fill( 0, 0, WIDTH , HEIGHT, _background );
        _row = 0;
        _column = 0;
    }

    /** Set a pixel on te screen
     *
     * @param x horizontal position from left
     * @param y vertical position from top
     * @param colour 24-bit colour in format 0x00RRGGBB
     */

    virtual void pixel( int x, int y, int colour ) {
        _cs = 0;
        _window( x, y, 1, 1 );
        _putp( colour );
        _cs = 1;
    }

    /** Fill an area of the screen
     *
     * @param x horizontal position from left
     * @param y vertical position from top
     * @param width width in pixels
     * @param height height in pixels
     * @param colour 24-bit colour in format 0x00RRGGBB
     */

    void fill( int x, int y, int width, int height, int colour ) {
        _cs = 0;
        _window( x, y, width, height );

        for (int i = 0; i < width * height; i++ ) {
            _putp( colour );
        }

        _window( 0, 0, WIDTH, HEIGHT );
        _cs = 1;
    }

    void blit( int x, int y, int width, int height, const int* colour ) {
        _cs = 0;
        _window( x, y, width, height );

        for (int i = 0; i < width * height; i++ ) {
            _putp( colour[i] );
        }
        _window( 0, 0, WIDTH, HEIGHT );
        _cs = 1;
    }

    void bitblit( int x, int y, int width, int height, const char* bitstream ) {
        _cs = 0;
        _window( x, y, width, height );

        for (int i = 0; i < height * width; i++ ) {
            int byte = i / 8;
            int bit = i % 8;
            int colour = ((bitstream[ byte ] << bit) & 0x80) ? _foreground : _background;
            _putp( colour );
        }
        _window( 0, 0, _width, _height );
        _cs = 1;
    }

    /** Screen width
     *
     *  @return screen width [pixel]
     */
    int width() {
        return WIDTH;
    }

    /** Screen height
     *
     *  @return screen height [pixel]
     */
    int height() {
        return HEIGHT;
    }
    /** Columns
     *
     *  @return screen columns
     */
    int columns() {
        return COLS;
    }

    /** Rows
     *
     *  @return screen rows
     */
    int rows() {
        return ROWS;
    }

    /** Power switch for OLED backlight
     *
     * @param sw argument can be MARMEX_OB_oled::ON or MARMEX_OB_oled::OFF
     */

    void power( unsigned char sw ) {
        _power_pin  = sw;
    }

virtual int _putc(int value) {
    int x = _column * 8;  // FIXME: Char sizes
    int y = _row * 8;
    bitblit(x + 1, y + 1, 8, 8, (char*)&(MARMEX_OB_oled::FONT8x8[value - 0x1F][0]));

    _column++;

    if (_column >= COLS) {
        _row++;
        _column = 0;
    }

    if (_row >= ROWS) {
        _row = 0;
    }

    return value;
}

virtual int write(const char c) {
	_putc(c);
	return (1);
}
// Printを継承するとサイズがオーバーするので、printだけ実装
int print(const char *s) {
	int len = strlen(s);
	if (s == 0)
		return 0;
	while (*s)
		write(*s++);
	return len;
}

void locate(int column, int row) {
    _column = column;
    _row = row;
}

enum {
	fontlength = 97,
	fontsize   = 8
};
static const unsigned char FONT8x8[fontlength][fontsize];

private:
    /** Command list for the OLED controller */
    enum {
        SET_DISPLAY_MODE_ALL_OFF                = 0xA4,
        SET_COMMAND_LOCK                        = 0xFD,
        SET_SLEEP_MODE_ON                       = 0xAE,
        FRONT_CLOCK_DRIVER_OSC_FREQ             = 0xB3,
        SET_MUX_RATIO                           = 0xCA,
        SET_DISPAY_OFFSET                       = 0xA2,
        SET_DISPAY_START_LINE                   = 0xA1,
        SET_REMAP_COLOR_DEPTH                   = 0xA0,
        SET_GPIO                                = 0xB5,
        FUNCTION_SELECTION                      = 0xAB,
        SET_SEGMENT_LOW_VOLTAGE                 = 0xB4,
        SET_CONTRAST_CURRENT_FOR_COLOR_ABC      = 0xC1,
        MASTER_CONTRAST_CURRENT_CONTROL         = 0xC7,
        LOOKUP_TABLE_FOR_GRAYSCALE_PULSE_WIDTH  = 0xB8,
        SET_RESET_PRECHARGE_PERIOD              = 0xB1,
        ENHANCE_DRIVING_SCHEME_CAPABILITY       = 0xB2,
        SET_PRECHARGE_VOLTAGE                   = 0xBB,
        SET_SECOND_PRECHARGE_VOLTAGE            = 0xB6,
        SET_VCOMH_VOLTAGE                       = 0xBE,
        SET_DISPLAY_MODE_RESET                  = 0xA6,
        SET_COLUMN_ADDRESS                      = 0x15,
        SET_ROW_ADDRESS                         = 0x75,
        WRITE_RAM_COMMAND                       = 0x5C,
        SET_SLEEP_MODE_OFF                      = 0xAF
    };

#ifdef MARMEX_OB_SPI_8BIT_MODE
    void command( int value ) {
        int tmp = value & 0x00ff;
        _cs = 0;
        _spi.write( tmp >> 1 );
        _spi.write( tmp << 7 );
        _cs = 1;
    }

    void data( int value ) {
        int tmp  = value & 0x00ff;
        tmp |= 0x0100;
        _cs = 0;
        _spi.write( tmp >> 1 );
        _spi.write( tmp << 7 );
        _cs = 1;
    }
#else
    void command( int value ) {
        _cs = 0;
        _spi.write( value & 0xFF );
        _cs = 1;
    }

    void data(int value) {
        _cs = 0;
        _spi.write( value | 0x100 );
        _cs = 1;
    }
#endif

    /*virtual*/ void _window( int x, int y, int width, int height ) {
        int x1 = x + 0;
        int y1 = y + 0;
        int x2 = x1 + width - 1;
        int y2 = y1 + height - 1;

        command( SET_COLUMN_ADDRESS );
        data( x1 );
        data( x2 );
        command( SET_ROW_ADDRESS );
        data( y1 );
        data( y2 );
        command( WRITE_RAM_COMMAND );
    }

    void window( int x, int y, int width, int height ) {
        _cs = 0;
        _window( x, y, width, height );
        _cs = 1;
    }

    /*virtual*/ void _putp( int colour ) {
        int cnv = 0;

        cnv  = (colour >> 8) & 0xf800;
        cnv |= (colour >> 5) & 0x07e0;
        cnv |= (colour >> 3) & 0x001f;

        data( cnv >> 8);
        data( cnv );
    }

protected:
    DigitalOut _power_pin;
    SPI _spi;
    DigitalOut _rst;
    DigitalOut _cs;

    int _row, _column, _rows, _columns, _foreground, _background, _width, _height;


}
;

#ifdef  MARMEX_OB_SPI_8BIT_MODE
#define MERMEX_OB_SPI_MODE_STR  "8bit mode"
#else
#define MERMEX_OB_SPI_MODE_STR  "9bit mode"
#endif
#endif  //  MBED_MARMEX_OB_OLED

/*
 *  history:
 *      0.5  (2011-Apr-07) :  initial published version
 *      0.51 (2011-Apr-08) :  a. "virtual" had been added on "_putp()" function definition to surpress warning when compiling (is this correct way?)
 *                            b. sample code (for Doxygen) is changed from new "main.cpp (ver 0.51)" 
 */

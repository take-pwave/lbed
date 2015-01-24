#ifndef MY_PRINT_H
#define MY_PRINT_H

#include <string.h>
// Arduinoのprint.hから最低限の機能を取り込む

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
	private:
	int printNumber(unsigned long, int);
	int printFloat(double number, int digits);
	public:
    int write(const char *s) {
      if (s == 0) return 0;
      return write((const char *)s, strlen(s));
    }
    int print(const char *s);
    int print(char c);
    int print(int, int = DEC);
    int print(long, int = DEC);
    int print(unsigned long, int = DEC);
    int print(double, int = 2);

    int println(void);
    int println(const char *s);
    int println(char c);

#if 0
    void printf (
    	const char*	str,	// Pointer to the format string
    	...					// Optional arguments
    );
#endif
	protected:
    virtual int write(const char c) = 0;	// ここでは未定義、必ず上位クラスで定義すること
    virtual int write(const char *s, int size);
};
#endif

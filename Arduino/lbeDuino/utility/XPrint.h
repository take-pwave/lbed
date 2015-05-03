#ifndef LBED_XPRINT_H
#define LBED_XPRINT_H
#include <stdarg.h>

class XPrint : public Print {
public:
	XPrint() {}
	/*----------------------------------------------*/
	/* Formatted string output                      */
	/*----------------------------------------------*/
	/*  printf("%6d", -200);			"  -200"
	    printf("%02u", 5);				"05"
	    printf("%ld", 12345678L);		"12345678"
	    printf("%08LX", 0x123ABC);		"00123ABC"
	    printf("%016b", 0x550F);		"0101010100001111"
	    printf("%s", "String");			"String"
	    printf("%c", 'a');				"a"
	*/

#if 1
    void printf (
    	const char*	str,	// Pointer to the format string
    	...					// Optional arguments
    );
#endif
protected:
    int write(const char c) { print(c); }
    int write(const char *s) { print(s); }

};
#endif

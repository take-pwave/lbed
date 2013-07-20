#include "Print.h"
#include <stdarg.h>

/* default implementation: may be overridden */
int Print::write(const char *s, int size) {
	int n = 0;
	while (size--) {
		n += write(*s++);
	}
	return n;
}

int Print::print(const char *s) {
	return write(s);
}

int Print::print(char c) {
	return write(c);
}

int Print::print(double n, int digits)
{
  return printFloat(n, digits);
}

int Print::println(void) {
	int n = print('\r');
	n += print('\n');
	return n;
}

int Print::println(const char *s) {
	int n = print(s);
	n += println();
	return n;
}

int Print::println(char c) {
	int n = print(c);
	n += println();
	return n;
}

#define	xputc(c)	write(c)
#define xputs(s)	write(s)

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

#if 0
void Print::printf (
	const char*	str,	/* Pointer to the format string */
	...					/* Optional arguments */
)
{
	va_list arp;
	unsigned int r, i, w, f;
	unsigned long val;
	char s[16], c, d;


	va_start(arp, str);

	while ((c = *str++) != 0) {
		if (c != '%') {
			xputc(c); continue;
		}
		c = *str++;
		f = 0;
		if (c == '0') {				/* Flag: '0' padded */
			f = 1; c = *str++;
		}
		w = 0;
		while (c >= '0' && c <= '9') {	/* Minimum width */
			w = w * 10 + c - '0';
			c = *str++;
		}
		if (c == 'l' || c == 'L') {	/* Prefix: Size is long int */
			f |= 2; c = *str++;
		}
		if (!c) break;
		d = c;
		if (d >= 'a') d -= 0x20;
		switch (d) {				/* Type is... */
		case 'S' :					/* String */
			xputs(va_arg(arp, char*)); continue;
		case 'C' :					/* Character */
			xputc((char)va_arg(arp, int)); continue;
		case 'B' :					/* Binary */
			r = 2; break;
		case 'O' :					/* Octal */
			r = 8; break;
		case 'D' :					/* Signed decimal */
		case 'U' :					/* Unsigned decimal */
			r = 10; break;
		case 'X' :					/* Hexdecimal */
			r = 16; break;
		default:					/* Unknown */
			xputc(c); continue;
		}

		/* Get an argument and put it in numeral */
		val = (f & 2) ? va_arg(arp, long) : ((d == 'D') ? (long)va_arg(arp, int) : va_arg(arp, unsigned int));
		if (d == 'D' && (val & 0x80000000)) {
			val = 0 - val;
			f |= 4;
		}
		i = 0;
		do {
			d = (char)(val % r); val /= r;
			if (d > 9)
				d += (c == 'x') ? 0x27 : 0x07;
			s[i++] = d + '0';
		} while (val && i < sizeof(s));
		if (f & 4) s[i++] = '-';
		while (i < w--) xputc((f & 1) ? '0' : ' ');
		do xputc(s[--i]); while(i);
	}

	va_end(arp);
}
#endif

int Print::print(unsigned long n, int base)
{
  if (base == 0) return write(n);
  else return printNumber(n, base);
}

int Print::print(int n, int base)
{
  return print((long) n, base);
}

int Print::print(long n, int base)
{
  if (base == 0) {
    return write(n);
  } else if (base == 10) {
    if (n < 0) {
      int t = print('-');
      n = -n;
      return printNumber(n, 10) + t;
    }
    return printNumber(n, 10);
  } else {
    return printNumber(n, base);
  }
}

int Print::printNumber(unsigned long n, int base) {
  char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';

  // prevent crash if called with base == 1
  if (base < 2) base = 10;

  do {
    unsigned long m = n;
    n /= base;
    char c = m - base * n;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  return write(str);
}

int Print::printFloat(double number, int digits)
{
  int n = 0;

  //if (isnan(number)) return print("nan");
  //if (isinf(number)) return print("inf");
  if (number > 4294967040.0) return print ("ovf");  // constant determined empirically
  if (number <-4294967040.0) return print ("ovf");  // constant determined empirically

  // Handle negative numbers
  if (number < 0.0)
  {
     n += print('-');
     number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (int i=0; i<digits; ++i)
    rounding /= 10.0;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  n += print(int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
    n += print(".");
  }

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    int toPrint = int(remainder);
    n += print(toPrint);
    remainder -= toPrint;
  }

  return n;
}

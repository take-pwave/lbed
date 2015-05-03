#include <stdarg.h>
#include "Arduino.h"
#include "lbed.h"

#define	xputc(c)	write(c)
#define xputs(s)	write(s)

#if 1
void XPrint::printf(const char* str, /* Pointer to the format string */
... /* Optional arguments */
) {
	va_list arp;
	unsigned int r, i, w, f;
	unsigned long val;
	char s[16], c, d;

	va_start(arp, str);

	while ((c = *str++) != 0) {
		if (c != '%') {
			xputc(c);
			continue;
		}
		c = *str++;
		f = 0;
		if (c == '0') { /* Flag: '0' padded */
			f = 1;
			c = *str++;
		}
		w = 0;
		while (c >= '0' && c <= '9') { /* Minimum width */
			w = w * 10 + c - '0';
			c = *str++;
		}
		if (c == 'l' || c == 'L') { /* Prefix: Size is long int */
			f |= 2;
			c = *str++;
		}
		if (!c)
			break;
		d = c;
		if (d >= 'a')
			d -= 0x20;
		switch (d) { /* Type is... */
		case 'S': /* String */
			xputs (va_arg(arp, char*));continue;
			case 'C' : /* Character */
			xputc((char)va_arg(arp, int)); continue;
			case 'B' : /* Binary */
			r = 2; break;
			case 'O' : /* Octal */
			r = 8; break;
			case 'D' : /* Signed decimal */
			case 'U' : /* Unsigned decimal */
			r = 10; break;
			case 'X' : /* Hexdecimal */
			r = 16; break;
			default: /* Unknown */
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
			d = (char) (val % r);
			val /= r;
			if (d > 9)
				d += (c == 'x') ? 0x27 : 0x07;
			s[i++] = d + '0';
		} while (val && i < sizeof(s));
		if (f & 4)
			s[i++] = '-';
		while (i < w--)
			xputc((f & 1) ? '0' : ' ');
		do
			xputc(s[--i]);
		while (i);
	}

	va_end(arp);
}
#endif

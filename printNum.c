#include <stdio.h>
#include "Main.h"

/**
 * printnum - functin that prints an integer
 * @n: input integer parameter
 **/

void printnum(int n)
{
	unsigned int m = n;

	if (n < 0)
	{
		_putchar(n);
		m = -m;

	if (m / 10)
	{
		printnum(m / 10);
	}
	_putchar(m % 10 + '0');
}
}

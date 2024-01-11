#include <stdio.h>

/**
 * puts - prints string of the parameter
 * @str: string
 */

void puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

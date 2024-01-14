#include "Main.h"

/**
 * _puts -  prints string of the parameter
 * @str: string parameter
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}

}

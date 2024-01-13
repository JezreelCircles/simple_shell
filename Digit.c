#include <stdio.h>
#include <ctype.h>

/**
 * AllDigits - name of the function
 * @s: string
 * Return: 1 if successful otherwise 0
 *
 *
 */

int AllDigits(char *s)
{
	while (*s != '\0')
	{
		if (!isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

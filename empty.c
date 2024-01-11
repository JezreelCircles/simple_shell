#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * is_empty_spaces - function name
 * @strs: string
 * Return: int
 */

int is_empty_spaces(char *strs)
{
	char *str = strdup(strs);
	char *original_str = str;

	while (*str)
	{
		if (!isspace((unsigned char)*str))
		{
			free(original_str);
			return (0);
		}
		str++;
	}
	free(original_str);
	return (1);
}

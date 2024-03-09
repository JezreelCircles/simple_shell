#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * strtok - block the use of strtok
 * @delimiters: of the function
 * @str: string
 * Return: NULL
 */

char *strtok(char *str, const char *delimiters)
{
	static char *saveptr;

	char *token_str;

	if (str != NULL)
		saveptr = str;

	if (saveptr == NULL || *saveptr == '\0')
	{
		return (NULL);
	}
	while (*saveptr != '\0' && strchr(delimiters, *saveptr) != NULL)
	{
		saveptr++;
	}
	if (*saveptr == '\0')
		return (NULL);

	token_str = saveptr;
	while (*saveptr != '\0' && strchr(delimiters, *saveptr) == NULL)
	{
		saveptr++;
	}

	if (*saveptr != '\0')
	{
		*saveptr = '\0';
		saveptr++;
	}

	return (token_str);
}

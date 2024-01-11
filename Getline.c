#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * _getline - function reads line
 * @ptr: pointer that stores the line
 * @n: the size
 * @stream: the stream
 * Return: 1 o succses
 */

int _getline(char **ptr, int *n, FILE *stream)
{
	char c, *temp;
	int size = 0;

	if (*n == 0 || *ptr == NULL)
	{
		*n = 128;
		*ptr = malloc(sizeof(char) * *n);
		if (*ptr == NULL)
			return (-1);
	}

	while ((c = getc(stream)) != '\n' && c != EOF)
	{
		if (size >= *n - 1)
		{
			*n *= 2;
			temp = realloc(*ptr, sizeof(char) * *n);

			if (temp == NULL)
			{
				free(*ptr);
				*ptr = NULL;
				return (-1);
			}
			*ptr = temp;
		}
		(*ptr)[size] = c;
		size++;
	}

	(*ptr)[size] = '\0';
	if (size == 0 && c == EOF)
		return (-1);

	return (1);
}

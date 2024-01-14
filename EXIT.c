#include "Main.h"

/**
 **_strncpy - copies a string
 *@destn: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */

char *_strncpy(char *destn, char *src, int n)
{
	int a, b;
	char *s = destn;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		destn[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			destn[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int aa, bb;
	char *s = dest;

	aa = 0;
	bb = 0;
	while (dest[aa] != '\0')
		aa++;
	while (src[bb] != '\0' && bb < n)
	{
		dest[aa] = src[bb];
		aa++;
		bb++;
	}
	if (bb < n)
		dest[aa] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: string to be passed
 *@c: character to look for
 *Return: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

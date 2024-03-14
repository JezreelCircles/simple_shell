#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - function that writes the character c to standard output
 * @c: character to be printed
 * Return: 1 on success, -1 on error and errno is set appropriately
*/

int _putchar (char c)
{
    return (write(1, &c, 1));
}
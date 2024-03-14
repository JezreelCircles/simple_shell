#include <stdio.h>
#include "main.h"

/**
 * _puts - function that prints string of a parameter
 * @str: string parameter
*/

void _puts(char *str)
{
    while (*str != '\0')
    {
        _putchar (*str);
        str++;
    }
}
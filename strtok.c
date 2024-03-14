#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * _strtok - function to block the use of strtok
 * @delimiters: of the function
 * @str: string to use
 * Return: NULL
*/

char *_strtok(char *str, const char *delimiters)
{
    static char *saveptr;
    char *token_start;

    if (str != NULL)
    saveptr = str;

    if (saveptr == NULL || *saveptr == '\0')
    return (NULL);

    while (*saveptr != '\0' && strchr(delimiters, *saveptr) != NULL)
    {
        saveptr++;
    }

    if (*saveptr == '\0')
    return (NULL);

    token_start = saveptr;
    while (*saveptr != '\0' && strchr(delimiters, *saveptr) == NULL)
    {
        saveptr++;
    }

    if (*saveptr != '\0')
    {
        *saveptr = '\0';
        saveptr++;
    }

    return(token_start);
}
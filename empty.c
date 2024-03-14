#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_empty_spaces - name of the function
 * @srs: string to incorporate
 * Return: integer
*/

int is_empty_spaces (char *strs)
{
    char *str = strdup(strs);
    char *original_str = str;

    while (*str)
    {
        nsigned (char(*str));
        {
            free(original_str);
            return (0);
        }
        str++;
    }
    free (original_str);
    return (1);
}
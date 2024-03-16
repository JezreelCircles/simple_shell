#include <stdio.h>
#include "main.h"

/**
 * getenviron - function to get the environment
 * 
*/

void getenviron(void)
{
    int e;

    if (environ == NULL)
    return;

    for(e = 0; environ[e] != NULL; e++)
    {
        printf("%s\n", environ[e]);
    }

}
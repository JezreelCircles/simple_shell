#include <stdio.h>
#include <string.h>

/**
 * commentsAfterHash - function that comments every character after hash sign
 * @str: string to be used
*/

void commentAfterHash (char str[])
{
    int i, HashIndex, Len;

Len = strlen(str)

for (i = 0; i < Len; i++;)
{
    if(str[i] == '#')
    {/*find the has character here*/}
    HashIndex = i;
    break;
}

for(i = HashIndex + 1; i < Len; i++;)
{
str[i] = '\0'; /*replace each character with "/" after hash the symbol*/
}
printf("commentedstring: %s\n", str);
}
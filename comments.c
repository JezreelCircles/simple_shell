#include <stdio.h>
#include <string.h>

/**
 * commentAfterhash - comment out everything after hash symbol
 * @str: string
 */

void commentAfterhash(char str[])
{
	int a, hashin, len;

	len = strlen(str);

	for (a = 0; a < len; len++)
	{
		if (str[a] == '#')
		{	/*finding hash */
		hashin = a;
		break;
		}
	}
	for (a = hashin + 1; a < len; len++)
	{
		str[a] = '\0'; /* replace every character with hash*/
	}

	printf("String commented: %s\n", str);
}

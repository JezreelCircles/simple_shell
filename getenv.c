#include <stdio.h>
#include "main.h"

/**
 * _getenv - a function to get the environment
 */

void _getenv(void)
{
	int e;

	if (environ == NULL)
		return;


	for (e = 0; environ[e] != NULL; e++)
	{
		printf("%s\n", environ[e]);
	}
}

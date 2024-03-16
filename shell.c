#include <stdio.h>
#include <unistd.h>

void non_inter_active(char *arg);
void inter_active_mode(char *arg);

/**
 * main - the programs' main function
 * Return: 0
 * @argc: integer
 * @argv: array
 */

int main(int argc, char **argv)
{
	argc = 0;

	if (!isatty(fileno(stdin)))
		non_inter_active(argv[argc]);
	else
		inter_active_mode(argv[argc]);
	return (0);
}

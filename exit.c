#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



/**
 * other_error - function print eror
 * @args: array
 * @p: name of pro
 */
void other_error(char **args, char *p)
{
	char errorMessage[100];
	int n = 1;

	while (args[n] != NULL)
		n++;

	sprintf(errorMessage, "%s: %d: exit: Illegal number: %s", p, n - 1,  args[1]);
	fprintf(stderr, "%s\n", errorMessage);
}
/**
 * exit_status - function name
 * @number: exit number
 * @program: name of program
 */
void exit_status(int number, char *program)
{
	char number_str[12], errorMessage[100];
	int fd;

	if (number < 0)
	{
		sprintf(errorMessage, "%s 1: exit: Illegal number: %d", program,  number);
		fprintf(stderr, "%s\n", errorMessage);
		number = 2;
	}

	fd = open("exit_status.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		perror("Error opening file");
		return;
	}
	snprintf(number_str, sizeof(number_str), "%d\n", number);
	if (write(fd, number_str, strlen(number_str)) == -1)
	{
		perror("Error writing to file");
		close(fd);
		return;
	}
	close(fd);
}

/**
 * read_exit_status - function name
 * @args: array to save the exit
 */

void read_exit_status(char **args)
{
	int fd = open("exit_status.txt", O_RDONLY);
	char buffer[1024];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

	if (fd == -1)
	{
		perror("Error opening file");
		return;
	}
	if (bytes_read == -1)
	{
		perror("Error reading from file");
		close(fd);
		return;
	}
	buffer[bytes_read] = '\0';
	buffer[strcspn(buffer, "\n")] = '\0';
	args[1] = strdup(buffer);
	args[2] = NULL;
	close(fd);
}

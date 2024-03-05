#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Main.h"
#define  L 1024

/**
 * active - activate shell to interactive mode
 * @args: array
 * @line: string
 * @status: integer
 * @handle: integer
 * Return: integer handler
 */
int active(char **args, char *line, int status, int handle)
{
	pid_t pid;

		pid = fork();
		if (pid == 0)
		{
			handle = child_process(args, line);
		}
		else if (pid > 0)
		{
			status = 0;
			waitpid(pid, &status, 0);
			if (status > 2)
				status = 2;
			exit_status(status);
			return (status);
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		return (handle);
}
/**
 * Memory - function name
 * @args: array
 * @line: string
 */
void Memory(char **args, char **line)
{
	int i = 0;

	if (*line != NULL)
	{
		free(*line);
		line = NULL;
	}
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
}

/**
 * Process - function name
 * @tken: the token word
 * @handle: integer
 * @args: array
 * @cd: character
 * @line: to free string
 * Return: integer
 */

int Process(char *tken, int handle, char **args, char *cd, char *line)
{
		if (is_empty_spaces(tken))
		{
			Memory(args, &line);
			return (1);
		}

		if (strcmp(tken, "clear") == 0)
		{
			Memory(args, &line);
			_puts("\033[2J\033[H");
			return (1);
		}
		if (strcmp(tken, "env") == 0)
		{
			Memory(args, &line);
			_getenv();
			return (1);
		}
		if (strcmp(tken, "cd") == 0 && chdir(args[1]) == 0)
		{
			Memory(args, &line);
			getcwd(cd, sizeof(cd));
			return (1);
		}
		if (handle)
		{
			Memory(args, &line);
			return (1);
		}
		return (0);
}

/**
 * inter_active_mode - check if the shell is in an interactive mode
 * @program: name of program
 */

void inter_active_mode(char *program)
{
	char *line = NULL, input[L];
	int handle, status, len = 0;
	char *args[L], *tken, cd[L];

	while (1)
	{
		line = NULL;
		_puts("$ ");
		if (_getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}
		strncpy(input, line, sizeof(input));
		input[strcspn(input, "\n")] = '\0';
		line[strcspn(line, "\n")] = '\0';
		if (is_empty_spaces(line))
		{
			args[0] = NULL;
			Memory(args, &line);
			continue;
		}
		tken = strtok(line, " ");
		while (tken == NULL && line == NULL)
			tken = _strtok(NULL, " ");
		if (tken == NULL || strcmp(tken, "") == 0 || strcmp(tken, " ") == 0)
		{
			Memory(args, &line);
			continue;
		}
		handle = token_input(input, args, program, line, handle);
		if (Process(tken, handle, args, cd, line))
			continue;
		handle = active(args, line, status, handle);
		status = 0;
		Memory(args, &line);
	}
	exit_status(handle);
	exit(handle);
}

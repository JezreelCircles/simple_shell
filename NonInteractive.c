#include "Main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  L 1024

/**
 * nonInteractive - non interactive mode function name
 * @program: program name
 *
 */

void nonInteractive(char *program)
{
	char *line = NULL, input[L], *args[L], *tken, cd[L];
	int handle, Status, length = 0;

	while (1)
	{
		line = NULL;
		if (_getline(&line, &length, stdin) == -1)
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
		tken = _strtok(line, " ");
		while (tken == NULL && line == NULL)
			tken = _strtok(NULL, " ");
		if (tken == NULL || strcmp(tken, "") == 0 || strcmp(tken, " ") == 0)
		{
			Memory(args, &line);
			continue;
		}
		handle = token_input(input, args, program, line, handle);
		if (Process(tken, handle, args, cd, line))
		{
			Memory(args, &line);
			continue;
		}
		handle = active(args, line, Status, handle);
		Status = 0;
		Memory(args, &line);
	}
	exit_status(handle);
	exit(handle);
}

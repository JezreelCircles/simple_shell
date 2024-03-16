#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define  L 1024

/**
 * non_inter_active - function name
 * @program: program name
 */

void non_inter_active(char *program)
{
	char *line = NULL, input[L], *args[L], *tken, cd[L];
	int handle, status, len = 0;

	while (1)
	{
		line = NULL;
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
			memory(args, &line);
			continue;
		}
		tken = _strtok(line, " ");
		while (tken == NULL && line == NULL)
			tken = _strtok(NULL, " ");
		if (tken == NULL || strcmp(tken, "") == 0 || strcmp(tken, " ") == 0)
		{
			memory(args, &line);
			continue;
		}
		handle = token_input(input, args, program, line, handle);
		if (process(tken, handle, args, cd, line))
		{
			memory(args, &line);
			continue;
		}
		handle = important(args, line, status, handle);
		status = 0;
		memory(args, &line);
	}
	exit_status(handle);
	exit(handle);
}


#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * is_builtin - function that checks if a command is an inbuilt
 * @cmd: the command
 * Return: returns the index of the inbuilt,
 * -1 if command isn't an inbuilt or if command is null
 */
int is_builtin(char *cmd)
{
	builtin command[] = {
		{"env", &env_func},
		{"exit", &exit_func},
		{NULL, NULL}
	};
	int i = 0;

	if (!cmd)
		return (-1);
	while (command[i].cmd)
	{
		if (_strcmp(command[i].cmd, cmd) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

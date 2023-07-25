#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * is_builtin - function that checks if a command is an inbuilt
 * @cmd: the command
 * @env: the environment variable
 * @line: the line we're currently on
 * @argv: the argument vector
 * @buff: the buffer that was allocated in the getline
 * Return: returns the index of the inbuilt,
 * -1 if command isn't an inbuilt or if command is null
 */
int is_builtin(char **cmd, __attribute__((unused))char **env,
		int line, char **argv, char *buff)
{
	int i = 0;

	if (_strcmp("exit", cmd[0]) == 0)
	{
		exit_func(cmd, buff);
		_printf("%s: %d: exit: Illegal number: %s\n",
				argv[0], line, cmd[1]);
		free(cmd);
		return (1);
	}
	if (_strcmp("env", cmd[0]) == 0)
	{
		while (env[i])
		{
			_printf("%s\n", env[i]);
			i++;
		}
		free(cmd);
		return (1);
	}
	else
		return (-1);
}

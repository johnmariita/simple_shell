#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * exit_func - function that exits a program
 * @cmd: the exit command
 * @buff: the buff whose memory was allocated in the getline function
 */
void exit_func(char **cmd, char *buff)
{
	int i;

	if (!cmd[1])
	{
		_free(2, buff, cmd);
		exit(EXIT_SUCCESS);
	}
	i = _atoi(cmd[1]);
	if (i < 0)
		return;
	_free(2, buff, cmd);
	exit(i);
}

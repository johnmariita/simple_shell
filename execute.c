#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute - function that executes a command,
 * displays an error msg if the command is not found
 * @command: an array of strings i.e the commands
 * @args: the file name
 * @line: the line you're on in the shell
 */
void execute(char **command, char *args, int line)
{
	pid_t pid;

	if (access(command[0], F_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(command[0], command, NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		_printf("%s: %d: %s: not found\n", args, line, command[0]);
	}
}

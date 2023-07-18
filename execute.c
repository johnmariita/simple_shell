#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int pid;
	char *path = getenv("PATH");
	char *filename, *fullpath, *directory, *slash = "/", *cp_path;

	if (!command[0])
		return;
	if (access(command[0], F_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(command[0], command, NULL);
		else
			wait(NULL);
		return;
	}
	cp_path = strdup(path);
	filename = malloc(_strlen(command[0]) + 2);
	strcpy(filename, slash);
	strcat(filename, command[0]);
	directory = strtok(cp_path, ":");
	while (directory)
	{
		fullpath = malloc(_strlen(directory) + _strlen(filename) + 1);
		strcpy(fullpath, directory);
		strcat(fullpath, filename);
		if (access(fullpath, F_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(fullpath, command, NULL);
			else
				wait(NULL);
			_free(3, fullpath, filename, cp_path);
			return;
		}
		free(fullpath);
		directory = strtok(NULL, ":");
	}
	_free(2, filename, cp_path);
	_printf("%s: %d: %s: not found\n", args, line, command[0]);
}

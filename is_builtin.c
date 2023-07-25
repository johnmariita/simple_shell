#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
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
	if (_strcmp("cd", cmd[0]) == 0)
	{
		if (handle_cd(cmd) == 1)
		{
			free(cmd);
			return (1);
		}
		else
		{
			_printf("%s: %d: cd: can't cd to %s\n", argv[0],
					line, cmd[1]);
			free(cmd);
			return (1);
		}
	}
	else
		return (-1);
}

/**
 * handle_cd - function to handle changing directory
 * @cmd: the command
 * Return: retur ns 1 on success and -1 on an error
 */
int handle_cd(char **cmd)
{
	char cwd[1024];
	char *home, *recent;
	DIR *directory;

	if (cmd[1])
	{
		if (_strcmp(cmd[1], "-") == 0)
		{
			recent = getenv("OLDPWD");
			if (chdir(recent) < 0)
				return (-1);
			if (getcwd(cwd, sizeof(cwd)) == NULL)
				perror("getcwd error");
			if (setenv("PWD", cwd, 1) != 0)
				perror("setenv error");
			return (1);
		}
		directory = opendir(cmd[1]);
		if (!directory)
			return (-1);
		if (chdir(cmd[1]) < 0)
			return (-1);
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd error");
		if (setenv("PWD", cwd, 1) != 0)
			perror("setenv error");
		closedir(directory);
		return (1);
	}
	home = getenv("HOME");
	if (chdir(home) < 0)
		return (-1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd error");
	if (setenv("PWD", cwd, 1) != 0)
		perror("setenv error");
	return (1);
}

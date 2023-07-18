#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "shell.h"

/**
 * main - the main function
 * @argc: argument count
 * @argv: argument vector
 * Return: returns 0 on success
 */
int main(__attribute__((unused))int argc, char *argv[], char **env)
{
	char *buffer = NULL;
	char **cmd = NULL;
	size_t n = 1024;
	int line_count = 1, gl = 0;

	signal(SIGINT, &handle_sig);
	while (1)
	{
		if (isatty(STDOUT_FILENO) && isatty(STDIN_FILENO))
			_printf(":) ");
		gl = getline(&buffer, &n, stdin);
		if (gl == -1)
		{
			free(buffer);
			_printf("\n");
			exit(EXIT_SUCCESS);
		}
		remove_new_line(buffer);
		cmd = tokenify(buffer);
		execute(cmd, argv[0], line_count, env);
		free(buffer);
		free(cmd);
		if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
			exit(EXIT_SUCCESS);
		buffer = NULL;
		line_count++;
	}
	return (0);
}

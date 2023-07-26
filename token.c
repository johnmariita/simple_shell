#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * tokenify - function that splits a string into individual tokens
 * @usr_cmd: the string to be tokenified
 * Return: returns the tokens
 */
char **tokenify(char *usr_cmd)
{
	char **token;
	int i = 0, tok = 0;

	while (usr_cmd[i])
	{
		if (usr_cmd[i] == ' ')
			tok++;
		i++;
	}
	i = 0;
	token = malloc(sizeof(char *) * (tok + 2));
	if (usr_cmd == NULL)
		return (NULL);
	token[i] = strtok(usr_cmd, " ");
	i++;
	for (; token[i - 1]; i++)
	{
		token[i] = strtok(NULL, " ");
	}
	return (token);
}

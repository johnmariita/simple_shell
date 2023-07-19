#include <stdio.h>
#include "shell.h"

/**
 * env_func - function that prints the environment variable
 * @environ: the environment variable
 */
void env_func(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}

#include <stdio.h>
#include <stdlib.h>

/**
 * exit_func - function that exits
 * @environ: the environment variable
 */
void exit_func(__attribute__((unused))char **environ)
{
	exit(EXIT_SUCCESS);
}

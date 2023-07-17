#include <stdio.h>
#include "shell.h"

/**
 * remove_new_line - function that removes a new line
 * @buffer: the string to remove the new line
 */
void remove_new_line(char *buffer)
{
	int i = 0;

	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break;
		}
		i++;
	}
}

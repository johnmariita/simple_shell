#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - the main function
 * Return: returns 0 on success
 */
int main(void)
{
	char *buffer = NULL;
	size_t n = 0;

	while (1)
	{
		getline(&buffer, &n, stdin);
	}
	return (0);
}

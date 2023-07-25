#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _atoi - function that convert a string to integer
 * @str: the string to be converted
 * Return: returns the the integer after conversion
 */
int _atoi(char *str)
{
	int num = 0;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

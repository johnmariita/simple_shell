#include <stdio.h>

/**
 * _strlen - function that calculates the length of a string
 * @buff: the string
 * Return: returns the length of the string
 */
int _strlen(char *buff)
{
	int i = 0;

	while (buff[i])
		i++;
	return (i);
}

/**
 * _strcmp - function that compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: returns 0 if strings are the same, non 0 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

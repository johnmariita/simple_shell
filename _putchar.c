#include <unistd.h>

/**
 * _putchar - function that emulates the putchar function
 * @c: the character to be printed
 * Return: returns 1 on success
 * On error, -1 is rerurned
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

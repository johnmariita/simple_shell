#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * handle_int - function that converts an integer into a string
 * @num: the integer to be converted
 */
void handle_int(int num)
{
	int temp = num, i = 0, index = 0;
	char buf[1024] = "";

	if (num >= 0 && num <= 9)
		_putchar(num + '0');
	else
	{
		while (temp)
		{
			temp /= 10;
			i++;
		}
		index = i - 1;
		while (num)
		{
			buf[index] = (num % 10) + '0';
			num /= 10;
			index--;
		}
		buf[i] = '\0';
	}
	_printf("%s", buf);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "shell.h"

/**
 * _printf - function that emulates the printf
 * @format: the format of the string
 */
void _printf(char *format, ...)
{
	int c = 0, i = 0, ch_count = 0;
	va_list ap;
	char *str = NULL;

	va_start(ap, format);
	while (format[i])
	{
		ch_count = 0;
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(ap, int);
					_putchar(c);
					break;
				case 's':
					str = va_arg(ap, char *);
					while (str[ch_count])
					{
						_putchar(str[ch_count]);
						ch_count++;
					}
					break;
				case 'd':
					c = va_arg(ap, int);
					handle_int(c);
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
}

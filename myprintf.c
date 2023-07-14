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
	int c, i = 0;
	va_list ap;
	char *str;

	va_start(ap, format);
	while (format[i])
	{
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
					while (*str)
					{
						_putchar(*str);
						str++;
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

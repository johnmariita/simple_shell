#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _free - function that frees some memory
 * @count: the number of memory blocks to be freed
 */
void _free(int count, ...)
{
	void *ptr;
	va_list ap;
	int i = 0;

	va_start(ap, count);
	while (i < count)
	{
		ptr = va_arg(ap, void*);
		free(ptr);
		i++;
	}
	va_end(ap);
}

#include <signal.h>
#include "shell.h"

/**
 * handle_sig - function that handles a signal
 * @sig: the signal
 */
void handle_sig(int sig)
{
	(void) sig;
	_printf("\n:) ");
}

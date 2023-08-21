#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_percent - Print a percentage sign.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_percent(int *calc)
{
	_putchar('%');
	(*calc)++;
}

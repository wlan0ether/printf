#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_string - Print a string.
 * @param: A va_list containing the string to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_string(va_list param, int *calc)
{
	const char *stringd = va_arg(param, const char *);

	if (stringd == NULL)
	{
		stringd = "(null)";
	}

	while (*stringd)
	{
		_putchar(*stringd);
		stringd++;
		(*calc)++;
	}
}

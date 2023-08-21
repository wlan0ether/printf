#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_char - Print a character.
 * @param: A va_list containing the character to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_char(va_list param, int *calc)
{
	char c = va_arg(param, int);

	_putchar(c);
	(*calc)++;
}

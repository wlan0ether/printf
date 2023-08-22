#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_int - Prints an integer.
 * @param: A va_list containing the integer to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_int(va_list param, int *calc)
{
	int num = va_arg(param, int);
	int absolute_num = (num < 0) ? -num : num; /* Calculate absolute value*/
	int divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		(*calc)++;
	}

	/* Calculate the divisor to get the leftmost digit*/
	while (absolute_num / 10 != 0)
	{
		divisor *= 10;
		absolute_num /= 10;
	}

	while (divisor > 0)
	{
		_putchar((absolute_num / divisor) + '0');
		(*calc)++;
		absolute_num %= divisor;
		divisor /= 10;
	}
}

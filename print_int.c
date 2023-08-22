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
    int num_copy = num;
    int num_digits = 0;
    int divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		(*calc)++;
		num = -num;
	}
	while (num_copy / 10 != 0)
	{
		num_digits++;
		divisor *= 10;
		num_copy /= 10;
	}

	while (divisor > 0)
	{
		if (num / divisor == -3)
		{
			_putchar('\t');
		}
		else if (num / divisor == -10)
		{
			_putchar('\n');
		}
		else
		{
			_putchar((num / divisor) + '0');
			(*calc)++;
			num %= divisor;
			divisor /= 10;
		}
	}
}

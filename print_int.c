#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * print_int - This here prints an integer.
 * @param: A va_list containing the integer to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_int(va_list param, int *calc)
{
	int num;
	unsigned int absolute_num;
	int divisor;

	num = va_arg(param, int);
	absolute_num = (num < 0) ? -num : num; /*Use unsigned int for absolute value*/

	if (num < 0)
	{
		_putchar('-');
		(*calc)++;
	}
	/* Special case for INT_MIN*/
	if (absolute_num == (unsigned int)INT_MIN)
	{
		_putchar('2');
		(*calc)++;
		absolute_num = 147483648; /*remainder after subtracting 2000000000*/
	}

	divisor = 1;

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

/**
 * print_long - Prints a long integer.
 * @param: A va_list containing the long integer to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_long(va_list param, int *calc)
{
	long num;
	unsigned long absolute_num;
	unsigned long divisor;

	num = va_arg(param, long);
	absolute_num = (num < 0) ? -num : num;

	if (num < 0)
	{
		_putchar('-');
		(*calc)++;
	}

	if (absolute_num == (unsigned long)LONG_MIN)
	{
		_putchar('9'); /* The first digit of LONG_MIN*/
		(*calc)++;
		absolute_num = 223372036854775808; /* after subtracting 9000000000000000000*/
	}

	divisor = 1;

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

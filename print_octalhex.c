#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_unsigned - Prints an unsigned integer for %u format specifier.
 * @param: A va_list containing the unsigned integer to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_unsigned(va_list param, int *calc)
{
	unsigned int num = va_arg(param, unsigned int);
	unsigned int solute_num = num;
	unsigned int divisor = 1;

	while (solute_num / 10 != 0)
    {
		divisor *= 10;
		solute_num /= 10;
	}

	while (divisor > 0)
	{
		_putchar((solute_num / divisor) + '0');
		(*calc)++;
		solute_num %= divisor;
		divisor /= 10;
	}
}

/**
 * print_octal - Prints an octal number for %o format specifier.
 * @param: A va_list containing the octal number to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_octal(va_list param, int *calc)
{
	unsigned int num = va_arg(param, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		(*calc)++;
	}
	else
	{
		unsigned int msk = 1 << (sizeof(unsigned int) * 8 - 1);
		int leading_zeros = 1;

		while (msk)
		{
			if ((num & msk) && leading_zeros)
			{
				leading_zeros = 0;
			}
			if (!leading_zeros)
			{
				_putchar('0' + ((num & msk) ? 1 : 0));
				(*calc)++;
			}
			msk >>= 1;
		}
	}
}

/**
 * print_hex - Prints a hexadecimal number for %x or %X format specifier.
 * @param: A va_list containing the hexadecimal number to print.
 * @capital: 1 if the specifier is %X, 0 if %x.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_hex(va_list param, int capital, int *calc)
{
	unsigned int mask;

	unsigned int num = va_arg(param, unsigned int);
	char hex_chars[] = "0123456789abcdef";

	if (capital)
	{
		hex_chars[10] = 'A'; /* Use uppercase characters*/
	}

	mask = 0xf << (sizeof(unsigned int) * 8 - 4);

	while (mask)
	{
		_putchar(hex_chars[(num & mask) >> (sizeof(unsigned int) * 8 - 4)]);
		(*calc)++;
		mask >>= 4;
	}
}

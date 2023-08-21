#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * print_binary - function converts integer argument
 * to binary
 * @num: takes in the number of integers
 * @*calc: pointer to calc variable that counts number of
 * inputed argument
 */

void print_binary(unsigned int num, int *calc)
{
	int binary[32]; /* Assuming 32-bit integer for simplicity*/
	int mib = 0;
	int bim;

	if (num == 0)
	{
		_putchar('0');
		(*calc)++;
		return;
	}

	while (num > 0)
	{
		binary[mib++] = num % 2;
		num /= 2;
	}

	for (bim = mib - 1; bim >= 0; bim--)
	{
		_putchar(binary[bim] + '0');
		(*calc)++;
	}
}


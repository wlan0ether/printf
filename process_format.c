#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * process_format - The function here
 * Processes a format specifier.
 * @format: The format string.
 * @param: A va_list containing the arguments.
 * @calc: A pointer to an integer that tracks the character count.
 */
void process_format(const char **format, va_list param, int *calc)
{
	(*format)++; /* Move past the '%' */

	if (**format == ' ') /* Check for space after % */
	{
		_putchar(' ');
		(*calc)++;
	}
	else if (**format == 'c')
	{
		print_char(param, calc);
	}
	else if (**format == 's')
	{
		print_string(param, calc);
	}
	else if (**format == 'd' || **format == 'i')
	{
		print_int(param, calc);
	}
	else if (**format == 'b')
	{
		unsigned int num = va_arg(param, unsigned int);

		print_binary(num, calc);
	}
	else if (**format == '%')
	{
		print_percent(calc);
	}
	else if (**format == 'd' || **format == 'i')
	{
		print_int(param, calc);
	}
	else
	{
		_putchar('%');
		_putchar(**format);
		(*calc) += 2;
	}
}

#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * process_integer - Handles %d, %i, %ld, %li format specifiers.
 * @format: Pointer to the format string, updated to the next character.
 * @param: A va_list containing the arguments.
 * @calc: Tracks character count.
 */

static void process_integer(const char **format, va_list param, int *calc)
{
	int is_long = 0; /*A flag to check for long specifier (l)*/

	if (**format == 'l')
	{
		(*format)++; /*Move past 'l'*/
		is_long = 1;
	}

	if (**format == 'd' || **format == 'i')
	{
		if (is_long)
		{
			print_long(param, calc);
		}
		else
		{
			print_int(param, calc);
		}
	}
	else
	{
		/* Handle unsupported format specifiers after '%d' or '%li'*/
		_putchar('%');
		if (is_long)
		{
			_putchar('l');
		}
		_putchar(**format);
		(*calc) += (is_long ? 2 : 1);
	}
}


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
	else if (**format == 'd' || **format == 'i' || **format == 'l')
	{
		process_integer(format, param, calc);
	}
	else
	{
		_putchar('%');
		_putchar(**format);
		(*calc) += 2;
	}
}

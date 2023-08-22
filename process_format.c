#include <stdarg.h>
#include <stddef.h>
#include "main.h"


/**
 * process_unsigned_octal_hex - Processes %u, %o, %x, and %X format specifiers.
 * @format: Pointer to the format string, updated to the next character.
 * @param: A va_list containing the arguments.
 * @calc: Tracks character count.
 */
static void process_octal_hex(const char **format, va_list param, int *calc)
{
	if (**format == 'u')
	{
		print_unsigned(param, calc);
	}
	else if (**format == 'o')
	{
		print_octal(param, calc);
	}
	else if (**format == 'x')
	{
		print_hex(param, 0, calc); /* Lowercase hexadecimal*/
	}
	else if (**format == 'X')
	{
		print_hex(param, 1, calc); /* Uppercase hexadecimal*/
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
	else if (**format == 'd' || **format == 'i')
	{
		print_int(param, calc);
	}
	else if (**format == 'u' || **format == 'o'|| **format
				== 'x' || **format == 'X')
	{
		process_octal_hex(format, param, calc);
	}
	else
	{
		_putchar('%');
		_putchar(**format);
		(*calc) += 2;
	}
}

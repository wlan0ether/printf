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

/**
 * print_percent - Print a percentage sign.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_percent(int *calc)
{
	_putchar('%');
	(*calc)++;
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
	else if (**format == '%')
	{
		print_percent(calc);
	}
	else
	{
		_putchar('%');
		_putchar(**format);
		(*calc) += 2;
	}
}

/**
 * _printf - This function prints to the stdout.
 * @format: Lists of the various arguments to be passed.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list param;
	int calc = 0;

	va_start(param, format);

	if (format == NULL) /* Check for null before proceeding */
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%')
		{
			process_format(&format, param, &calc);
		}
		else
		{
			_putchar(*format);
			calc++;
		}
		format++;
	}
	va_end(param);
	return (calc);
}


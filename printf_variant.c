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
 * print_string - This Prints a string.
 * @param: A va_list containing the string to print.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_string(va_list param, int *calc)
{
	const char *stringd = va_arg(param, const char*);

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
 * print_percent - This function Prints a percentage sign.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_percent(int *calc)
{
	_putchar('%');
	(*calc)++;
}

/**
 * print_int - This Prints out an integer.
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
		_putchar((num / divisor) + '0');
		(*calc)++;
		num %= divisor;
		divisor /= 10;
	}
}

/**
 * _printf - This function prints to the standard output.
 * @format: Lists of the various arguments to be passed.
 * Return: Number of characters printed, in this case calc.
 */
int _printf(const char *format, ...)
{
	va_list param;
	int calc = 0;

	va_start(param, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == ' ')
			{
				_putchar('%');
				_putchar(' ');
				calc += 2;
			}
			else if (*format == 'c')
			{
				print_char(param, &calc);
			}
			else if (*format == 's')
			{
				print_string(param, &calc);
			}
			else if (*format == 'd' || *format == 'i')
			{
				print_int(param, &calc);
			}
			else if (*format == '%')
			{
				print_percent(&calc);
			}
			else
			{
				_putchar('%');
				calc++;
				_putchar(*format);
				calc++;
				return (-1);
			}
		}
		else
		{
			_putchar(*format);
			calc++;
		}
		format++;
	}

	va_end(param);

	return calc;
}


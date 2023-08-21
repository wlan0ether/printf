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
	int c = va_arg(param, int);
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
 * print_percent - Print a percentage sign.
 * @calc: A pointer to an integer that tracks the character count.
 */
void print_percent(int *calc)
{
	_putchar('%');
	(*calc)++;
}

/**
 * print_int - Print an integer.
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
 * _printf - This function prints to the stdout.
 * @format: Lists of the various arguments to be passed.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list param;
	int calc = 0;

	va_start(param, format);

	if (format == NULL || *format == '\0')
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == ' ' || !*(format + 1)))
		{
			print_percent(&calc);
			if (*(format + 1) == ' ')
			{
				_putchar(' ');
				calc++;
			}
			format += 2;
		}
		else if (*format == '%')
		{
			format++;
			if (*format == ' ')
			{
				_putchar(' ');
				calc++;
			}
			else if (*format == 'c')
			{
				print_char(param, &calc);
			}
			else if (*format == 's')
			{
				print_string(param, &calc);
			}
			else if(*format == 'd' || *format == 'i')
			{
				print_int(param, &calc);
			}
			else if (*format == '%')
			{
				print_percent(&calc);
			}
			else
			{
				print_percent(&calc);
				_putchar(*format);
				calc += 2;
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
	return (calc);
}


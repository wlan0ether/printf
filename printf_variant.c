#include "main.h"
#include <stdarg.h>
#include <stddef.h>

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

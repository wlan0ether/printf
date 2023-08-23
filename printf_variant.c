#include "main.h"

/**
 * _printf - This function prints to the stdout.
 * @format: Lists of the various arguments to be passed.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list param;
	unsigned int ib, calc = 0, str_count;

	if (!format || format[0] == '%' && format[1] == '\0')
	{
		return (-1);
	}

	va_start(param, format);

	for (ib = 0; format[ib] != '\0'; ib++)
	{
		if (format[ib] != '%')
		{
			_putchar(format[ib]);
		}
		else if (format[ib] == '%' && format[ib + 1] == 'c')
		{
			_putchar(va_arg(param, int));
			ib++;
		}
		else if (format[ib + 1] == 's')
		{
			str_count = _putss(va_arg(param, char *));
			ib++;
			calc += (str_count - 1);
		}
		else if (format[ib + 1] == '%')
		{
			_putchar('%');
		}
		calc++;
	}

	va_end(param);
	return (calc);
}

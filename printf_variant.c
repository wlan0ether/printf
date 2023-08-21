#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
* _printf - This function prints to the stdout.
* @format: Lists of the various arguments to be passed
* Return: number of character printed, calc.
*/
int _printf(const char *format, ...)
{
	va_list param;
	int c;
	const char *stringd;
	int calc = 0;

	va_start(param, format);

	if (format == NULL || *format == '\0') /*checks for null before proceeding*/
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* moves past the '%' */
			if (*format == ' ') /*this checks for space after %*/
			{
				_putchar(' ');
				calc++;
			}
			else if (*format == 'c')
			{
				c = va_arg(param, int);
				_putchar(c);
				calc++;
			}
			else if (*format == 's')
			{
				stringd = va_arg(param, const char*);

				while (*stringd)
				{
					_putchar(*stringd);
					stringd++;
					calc++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				calc++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				calc += 2;
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

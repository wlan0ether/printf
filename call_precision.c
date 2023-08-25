#include "main.h"

/**
 * call_precision - Function that calculates precision for printing
 * @format: String that will print the arguments
 * @j: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: fmt_prec.
 */
int call_precision(const char *format, int *j, va_list list)
{
	int curr_j = *j + 1;
	int fmt_prec = -1;

	if (format[curr_j] != '.')
		return (fmt_prec);

	fmt_prec = 0;

	for (curr_j += 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			fmt_prec *= 10;
			fmt_prec += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			fmt_prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (fmt_prec);
}


#include "main.h"

/**
 * call_width - This function calculates the width of inputs
 * @format: String holding the arguments.
 * @j: container for list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: wid.
 */
int call_width(const char *format, int *j, va_list list)
{
	int curr_j;
	int wid = 0;

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			wid *= 10;
			wid += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (wid);
}


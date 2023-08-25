#include "main.h"

/**
 * call_size - This function calculates size given to the argument
 * @format: String that prints arguments
 * @j: container for list of arguments to be printed.
 * Return: size.
 */
int call_size(const char *format, int *j)
{
	int present_j = *j + 1;
	int size = 0;

	if (format[present_j] == 'l')
		size = S_LONG;
	else if (format[present_j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*j = present_j - 1;
	else
		*j = present_j;

	return (size);
}


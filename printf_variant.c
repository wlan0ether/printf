#include "main.h"

void print_buffer(char buffer[], int *buff_idx);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters, calc.
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, calc = 0;
	int flag, wid, fmt_prec, size, buff_idx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_idx++] = format[j];
			if (buff_idx == BUFF_SIZE)
				print_buffer(buffer, &buff_idx);
			calc++;
		}
		else
		{
			print_buffer(buffer, &buff_idx);
			flag = call_flag(format, &j);
			wid = call_width(format, &j, list);
			fmt_prec = call_precision(format, &j, list);
			size = call_size(format, &j);
			++j;
			printed = trigger_print(format, &j, list, buffer,
				flag, wid, fmt_prec, size);
			if (printed == -1)
				return (-1);
			calc += printed;
		}
	}
	print_buffer(buffer, &buff_idx);
	va_end(list);
	return (calc);
}

/**
* print_buffer - This function outputs the contents of buffer if it exist
*
* @buffer: Array of characters
* @buff_idx: Index at wch 2 add nxt char also represents the length.
* Return: void
*/

void print_buffer(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);

	*buff_idx = 0;
}


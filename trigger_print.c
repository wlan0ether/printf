#include "main.h"

/**
 * trigger_print - This function prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @idx: index.
 * @buffer: Buffer array to handle print.
 * @flag: Calculates active flags
 * @wid: variable that gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int trigger_print(const char *fmt, int *idx, va_list list, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	int j, unknow_len = 0, printed_charr = -1;
	formt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_nonsigned}, {'o', print_octal}, {'x', hexadecimal_funct},
		{'X', print_higher_hexa}, {'p', pointer_variant}, {'S', non_printable},
		{'r', reverse_funct}, {'R', rot_13string}, {'\0', NULL}
	};

	for (j = 0; fmt_types[j].fmt != '\0'; j++)
	{
		if (fmt[*idx] == fmt_types[j].fmt)
			return (fmt_types[j].fn(list, buffer, flag, wid, fmt_prec, size));
	}
	if (fmt_types[j].fmt == '\0)
	{
		if (fmt[*idx] == '\0')
			return (-1);

		unknow_len += write(1, " %% ", 1);

		if (fmt[*idx - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wid)
		{
			--(*idx);

			while (fmt[*idx] != ' ' && fmt[*idx] != '%')
			{
				--(*idx);
			}
			if (fmt[*idx] == ' ')
				--(*idx);
			return (1);
		}
		unknow_len += write(1, &fmt[*idx], 1);
		return (unknow_len);
	}
	return (printed_charr);
}


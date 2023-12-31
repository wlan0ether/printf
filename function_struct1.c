#include "main.h"

/**
 * print_nonsigned - function that prints numbers
 * @param: container for list of arguments having unsigned data type
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that gets width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_nonsigned(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(param, unsigned long int);

	num = convert_unsyned(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flag, wid, fmt_prec, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - function outputs %u number in octal notation
 * @param: contains all list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: A variable that get width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int digit = va_arg(param, unsigned long int);
	unsigned long int init_digit = digit;

	UNUSED(wid);

	digit = convert_unsyned(digit, size);

	if (digit == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (digit > 0)
	{
		buffer[j--] = (digit % 8) + '0';
		digit /= 8;
	}

	if (flag & F_HASH && init_digit != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flag, wid, fmt_prec, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * hexadecimal_funct - outputs lower hexadecimal notation
 * @param: handles list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that fetches width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexadecimal_funct(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	return (print_hexa(param, "0123456789abcdef",
		buffer, flag, 'x', wid, fmt_prec, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_higher_hexa - outputs in upper hexadecimal notation
 * @param: handles inputted arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that fetches width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_higher_hexa(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	return (print_hexa(param, "0123456789ABCDEF",
		buffer, flag, 'X', wid, fmt_prec, size));
}

/************** PRINT HEX DIGITS IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @param: contains list of arguments
 * @map_to: Array of values to loop the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @wid: variable that gets width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list param, char map_to[], char buffer[],
	int flag, char flag_ch, int wid, int fmt_prec, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int digit = va_arg(param, unsigned long int);
	unsigned long int init_digit = digit;

	UNUSED(wid);

	digit = convert_unsyned(digit, size);

	if (digit == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (digit > 0)
	{
		buffer[j--] = map_to[digit % 16];
		digit /= 16;
	}

	if (flag & F_HASH && init_digit != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flag, wid, fmt_prec, size));
}


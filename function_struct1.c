#include "main.h"
 
/**
 * print_unsigned – function that prints an unsigned number
 * @param: container for list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that gets width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	int j = BUFF_SIZE - 2;
        	unsigned long int num = va_arg(param, unsigned long int);
 
        	num = convert_unsigned(num, size);
 
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
/**
 * print_octal – function outputs %u number in octal notation
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
 
        	digit = convert_unsigned(digit, size);
 
        	if (digit == 0)
                    	buffer[j--] = '0';
 
        	buffer[BUFF_SIZE - 1] = '\0';
 
        	while (num > 0)
        	{
                    	buffer[j--] = (digit % 8) + '0';
                    	digit /= 8;
        	}
 
        	if (flag & F_HASH && init_digit != 0)
                    	buffer[j--] = '0';
 
        	j++;
 
        	return (write_unsgnd(0, j, buffer, flag, wid, fmt_prec, size));
}

/**
 * print_hexadecimal – outputs lower hexadecimal notation
 * @param: handles list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that fetches width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	return (print_hexa(param, "0123456789abcdef", buffer,
                    	flag, 'x', wid, fmt_prec, size));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper – outputs in upper hexadecimal notation
 * @param: handles inputted arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that fetches width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	return (print_hexa(param, "0123456789ABCDEF", buffer,
                    	flag, 'X', wid, fmt_prec, size));
}

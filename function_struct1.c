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


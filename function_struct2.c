#include "main.h"
 
/**
 * print_pointer - Prints the value of a pointer variable
 * @param: handles list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that fetches width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	char extra_c = 0, filler = ' ';
        	int idx = BUFF_SIZE - 2, length = 2, filler_start = 1; /* length=2, for '0x' */
        	unsigned long num_adr;
        	char map_to[] = "0123456789abcdef";
        	void *addrs = va_arg(param, void *);
 
        	UNUSED(wid);
        	UNUSED(size);
 
        	if (addrs == NULL)
                    	return (write(1, "(nil)", 5));
 
        	buffer[BUFF_SIZE - 1] = '\0';
        	UNUSED(fmt_prec);
 
        	num_adr = (unsigned long)addrs;
 
        	while (num_adr > 0)
        	{
                    	buffer[idx--] = map_to[num_adr % 16];
                    	num_adr /= 16;
                    	length++;
        	}
 
        	if ((flag & F_ZERO) && !(flag & F_SUB))
                    	filler = '0';
        	if (flag & F_ADD)
                    	extra_c = '+', length++;
        	else if (flag & F_SPACE)
                    	extra_c = ' ', length++;
 
        	idx++;
 
        	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
        	return (write_pointer(buffer, idx, length,
                    	wid, flag, filler, extra_c, filler_start));
}

/**
 * print_non_printable - print ascii codes in hex of non printable chars
 * @param: container for list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that get width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	int j = 0, offset = 0;
        	char *str = va_arg(param, char *);
 
        	UNUSED(flag);
        	UNUSED(wid);
        	UNUSED(fmt_prec);
        	UNUSED(size);
 
        	if (str == NULL)
                    	return (write(1, "(null)", 6));
 
        	while (str[j] != '\0')
        	{
                    	if (is_printable(str[j]))
                                	buffer[j + offset] = str[j];
                    	else
                                	offset += append_hex_code(str[j], buffer, j + offset);
 
                    	j++;
        	}
 
        	buffer[j + offset] = '\0';
 
        	return (write(1, buffer, j + offset));
}


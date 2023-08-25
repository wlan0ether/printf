#include "main.h"

/**
 * handle_write_char – This function prints out a string you know
 * @c: character to be outputted or printed
 * @buffer: Buffer array in place to handle print
 * @flag:  Calculates active flags.
 * @wid: variable that fetches the width.
 * @fmt_prec: precision indicator
 * @size: Size indicator
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{ /* char is stored at left and filler at buffer's right */
        	int j = 0;
        	char filler = ' ';
 
        	UNUSED(fmt_prec);
        	UNUSED(size);
 
        	if (flag & F_ZERO)
                    	filler = '0';
 
        	buffer[j++] = c;
        	buffer[j] = '\0';
 
        	if (wid > 1)
        	{
                    	buffer[BUFF_SIZE - 1] = '\0';
                    	for (j = 0; j< wid - 1; j++)
                                	buffer[BUFF_SIZE - j - 2] = filler;
 
                    	if (flag & F_SUB)
                                	return (write(1, &buffer[0], 1) +
                                                        	write(1, &buffer[BUFF_SIZE - j - 1], wid - 1));
                    	else
                                	return (write(1, &buffer[BUFF_SIZE - j - 1], wid - 1) +
                                                        	write(1, &buffer[0], 1));
        	}
 
        	return (write(1, &buffer[0], 1));
}
/**
 * write_number – This function prints out a number
 * @is_negative: verifies if a number is negative -
 * @idx: index to be looped through.
 * @buffer: This buffer contains an array that handle printx
 * @flag:  Calculates active flags always
 * @wid: variable that get width.
 * @fmt_prec: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int idx, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	int length = BUFF_SIZE - idx - 1;
        	char filler = ' ', extra_ch = 0;
 
        	UNUSED(size);
 
        	if ((flag & F_ZERO) && !(flag & F_SUB))
                    	filler = '0';
        	if (is_negative)
                    	extra_ch = '-';
        	else if (flag & F_ADD)
                    	extra_ch = '+';
        	else if (flag & F_SPACE)
                    	extra_ch = ' ';
 
        	return (write_num(idx, buffer, flag, wid, fmt_prec,
                    	length, filler, extra_ch));
}


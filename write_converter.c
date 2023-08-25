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
/**
 * write_num – This function writesz a number using a bufffer
 * @idx: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Calculate flags that are active
 * @wid: width
 * @fmt_prec: Precision specifier
 * @length: Number length
 * @filler: adds extra character or space for alignment
 * @extra_c: contains the extra characters
 *
 * Return: Number of printed chars.
 */
int write_num(int idx, char buffer[],
        	int flag, int wid, int fmt_prec,
        	int length, char filler, char extra_c)
{
        	int j, filler_start = 1;
 
        	if (fmt_prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0' && wid == 0)
                    	return (0); /* no char is printed */
        	if (fmt_prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
                    	buffer[idx] = filler = ' '; /* width is displayd with filler ' ' */
        	if (fmt_prec > 0 && fmt_prec < length)
                    	filler = ' ';
        	while (fmt_prec > length)
                    	buffer[--idx] = '0', length++;
        	if (extra_c != 0)
                    	length++;
        	if (wid > length)
        	{
                    	for (j = 1; j < wid - length + 1; j++)
                                	buffer[j] = filler;
                    	buffer[j] = '\0';
                    	if (flag & F_SUB && filler == ' ')/* Assigns extra char to left of buffr */
                    	{
                                	if (extra_c)
                                            	buffer[--idx] = extra_c;
                                	return (write(1, &buffer[idx], length) + write(1, &buffer[1], j - 1));
                    	}
                    	else if (!(flags & F_SUB) && filler == ' ')/* extra char to left of buffr */
                    	{
                                	if (extra_c)
                                            	buffer[--idx] = extra_c;
                                	return (write(1, &buffer[1], j - 1) + write(1, &buffer[idx], length));
                    	}
                    	else if (!(flag & F_SUB) && filler == '0')/* extra char to left of filler */
                    	{
                                	if (extra_c)
                                            	buffer[--filler_start] = extra_c;
                                	return (write(1, &buffer[filler_start], j - filler_start) +
                                            	write(1, &buffer[idx], length - (1 - filler_start)));
                    	}
        	}
        	if (extra_c)
                    	buffer[--idx] = extra_c;
        	return (write(1, &buffer[idx], length));
}
/**
 * write_unsgnd – This function go give an unsigned number
 * @is_negative: A validator, if num is negative
 * @idx: Index at which numbers start in buffer
 * @buffer: Array of charactersx
 * @flag: Flags specifiers
 * @wid: Width specifier
 * @fmt_prec: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int idx,
        	char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	/* The number is stored at the bufer's right and starts at position j */
        	int length = BUFF_SIZE - idx - 1, j = 0;
        	char filler = ' ';
 
        	UNUSED(is_negative);
        	UNUSED(size);
 
        	if (fmt_prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
                    	return (0); /* no char is printed */
 
        	if (fmt_prec > 0 && fmt_prec < length)
                    	filler = ' ';
 
        	while (fmt_prec > length)
        	{
                    	buffer[--idx] = '0';
                    	length++;
        	}
 
        	if ((flag & F_ZERO) && !(flag & F_SUB))
                    	filler = '0';
 
        	if (wid > length)
        	{
                    	for (j = 0; j < wid - length; j++)
                                	buffer[j] = filler;
 
                    	buffer[j] = '\0';
 
                    	if (flag & F_SUB) /* Assigns extra char to left of buffer]*/
                    	{
                                	return (write(1, &buffer[idx], length) + write(1, &buffer[0], j));
                    	}
                    	else /* Assigns extra char to left of filler*/
                    	{
                                	return (write(1, &buffer[0], j) + write(1, &buffer[idx], length));
                    	}
        	}
 
        	return (write(1, &buffer[idx], length));
}


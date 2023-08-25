#include "main.h"
 
/**
 * is_printable – This function will valuates
 * if a char is printable
 * @c: This is the character that will be evaluated.
 * Return: returns 1 if c is printable, otherwise 0
 */
int is_printable(char c)
{
        	if (c >= 32 && c < 127)
                    	return (1);
 
        	return (0);
}
/**
 * append_hex_code – This inputs ascii in hexadecimal code to the buffer
 * @buffer: contains an array of chars.
 * @j: The Index where appending starts
 * @ascii_code: This contains the standard ASCII codes.
 * Return: returns 3 always
 */
int append_hex_code(char ascii_code, char buffer[], int j)
{
        	char map_to[] = "0123456789ABCDEF";
        	/* The hex format code is always 2 digits long */
        	if (ascii_code < 0)
                    	ascii_code *= -1;
 
        	buffer[i++] = '\\';
        	buffer[i++] = 'x';
 
        	buffer[i++] = map_to[ascii_code / 16];
        	buffer[i] = map_to[ascii_code % 16];
 
        	return (3);
}
/**
 * is_digit – Confirms that a char is digit
 * @a: The char that will be checked
 *
 * Return: if c is a number, returns 1, 0 otherwise
 */
int is_digit(char a)
{
        	if (a >= '0' && a <= '9')
                    	return (1);
 
        	return (0);
}
/**
 * convert_number_size - introduces a number to the specified size
 * @num: The number to be specified.
 * @size: Number that shows the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_number_size(long int num, int size)
{
        	if (size == S_LONG)
                    	return (num);
        	else if (size == S_SHORT)
                    	return ((short)num);
 
        	return ((int)num);
}


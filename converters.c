#include "main.h"

/**
 * is_print_ble - Checks if a character is printable.
 * @c: The character to evaluate.
 * Return: Returns 1 if c is printable, otherwise 0.
 */
int is_print_ble(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hex_code - Appends ASCII in hexadecimal code to the buffer.
 * @buffer: An array of characters.
 * @j: The index where appending starts.
 * @ascii_code: The standard ASCII code.
 * Return: Returns 3 always.
 */
int append_hex_code(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";

    /* The hex format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if a character is a digit.
 * @a: The character to check.
 * Return: Returns 1 if 'a' is a number, 0 otherwise.
 */
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);

	return (0);
}

/**
 * convert_number_size - Converts a number to the specified size.
 * @num: The number to be cast.
 * @size: The size specifying the type to cast to.
 * Return: Returns the casted value of num.
 */
long int convert_number_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_unsyned - Converts a number to the specified size.
 * @num: The number to be cast.
 * @size: The size specifying the type to cast to.
 * Return: Returns the value of num.
 */
long int convert_unsyned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}


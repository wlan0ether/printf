#include "main.h"

/**
 * handle_charac - This function prints out a character.
 * @c: Character to be printed.
 * @buffer: Buffer array to handle print.
 * @flag: Calculates active flags.
 * @wid: Variable that fetches the width.
 * @fmt_prec: Precision indicator.
 * @size: Size indicator.
 *
 * Return: Number of characters printed.
 */
int handle_charac(char c, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
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
		for (j = 0; j < wid - 1; j++)
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

/*** WRITE NUMBER *************************/
/**
 * write_digitber - This function prints out a number.
 * @is_negative: Verifies if a number is negative.
 * @idx: Index to be looped through.
 * @buffer: Buffer containing an array that handles print.
 * @flag: Calculates active flags always.
 * @wid: Variable that gets width.
 * @fmt_prec: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int write_digitber(int is_negative, int idx, char buffer[],
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

	return (write_digit(idx, buffer, flag, wid, fmt_prec,
		length, filler, extra_ch));
}

/**
 * write_digit - This function writes a number using a buffer.
 * @idx: Index at which the number starts in the buffer.
 * @buffer: Buffer.
 * @flag: Calculate flags that are active.
 * @wid: Width.
 * @fmt_prec: Precision specifier.
 * @length: Number length.
 * @filler: Adds extra character or space for alignment.
 * @extra_c: Contains the extra characters.
 *
 * Return: Number of printed characters.
 */
int write_digit(int idx, char buffer[], int flag, int wid,
	int fmt_prec, int length, char filler, char extra_c)
{
	int j, filler_start = 1;

	if (fmt_prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0' && wid == 0)
		return (0); /* no characters are printed */
	if (fmt_prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		buffer[idx] = filler = ' '; /* width is displayed with filler ' ' */
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
		if (flag & F_SUB && filler == ' ')
		{
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[idx], length) + write(1, &buffer[1], j - 1));
		}
		else if (!(flag & F_SUB) && filler == ' ') /*Xtrachar to buffer left */
		{
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[idx], length));
		}
		else if (!(flag & F_SUB) && filler == '0') /*Xtra char to filler left */
		{
			if (extra_c)
				buffer[--filler_start] = extra_c;
			buffer[1] = '0';
			return (write(1, &buffer[filler_start], j - filler_start) +
				write(1, &buffer[idx], length - (1 - filler_start)));
		}
	}
	if (extra_c)
		buffer[--idx] = extra_c;
	return (write(1, &buffer[idx], length));
}

/**
 * write_unsgnd - This function gives an unsigned number.
 * @is_negative: A validator, if num is negative.
 * @idx: Index at which numbers start in buffer.
 * @buffer: Array of characters.
 * @flag: Flags specifiers.
 * @wid: Width specifier.
 * @fmt_prec: Precision specifier.
 * @size: Size specifier.
 * Return: Number of written characters.
 */
int write_unsgnd(int is_negative, int idx, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	int length = BUFF_SIZE - idx - 1, j = 0;
	char filler = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (fmt_prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		return (0); /* no characters are printed */

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

		if (flag & F_SUB) /* Extra character to left of buffer */
		{
			return (write(1, &buffer[idx], length) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[idx], length));
		}
	}
	return (write(1, &buffer[idx], length));
}

/**
 * write_pointer - Outputs addresses in memory.
 * @buffer: Array of characters.
 * @idx: Index at which the number starts in the buffer.
 * @length: Length of the number.
 * @wid: Width getter.
 * @flag: Flags specifier.
 * @filler: Char representing the padding.
 * @extra_c: Char representing extra char.
 * @filler_start: Index at which filling should start.
 * Return: Number of written characters.
 */
int write_pointer(char buffer[], int idx, int length,
	int wid, int flag, char filler, char extra_c, int filler_start)
{
	int j;

	if (wid > length)
	{
		for (j = 3; j < wid - length + 3; j++)
			buffer[j] = filler;

		buffer[j] = '\0';

		if (flag & F_SUB && filler == ' ')
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[idx], length) + write(1, &buffer[3], j - 3));
		}
		else if (!(flag & F_SUB) && filler == ' ')
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[idx], length));
		}
		else if (!(flag & F_SUB) && filler == '0') /*Xtra char 2 filler left*/
		{
			if (extra_c)
				buffer[--filler_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[filler_start], j - filler_start) +
				write(1, &buffer[idx], length - (1 - filler_start) - 2));
		}
	}
	buffer[--idx] = 'x';
	buffer[--idx] = '0';
	if (extra_c)
		buffer[--idx] = extra_c;
	return (write(1, &buffer[idx], BUFF_SIZE - j - 1));
}


#include "main.h"

/**
 * print_char - Prints a char, just one to the stdout
 * @param: container for list of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @wid: variable that gets width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	char c = va_arg(param, int);

	return (handle_charac(c, buffer, flag, wid, fmt_prec, size));
}

/********** PRINT A STRING ************/
/**
 * print_string - Prints a string of characters or words
 * @param: container of list of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @wid: variable that gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	int length = 0, j;
	char *str = va_arg(param, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(fmt_prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (fmt_prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (fmt_prec >= 0 && fmt_prec < length)
		length = fmt_prec;

	if (wid > length)
	{
		if (flag & F_SUB)
		{
			write(1, &str[0], length);
			for (j = wid - length; j > 0; j--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (j = wid - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wid);
		}
	}

	return (write(1, str, length));
}

/*********** PRINT PERCENT SIGN*********/
/**
 * print_per_cent - Prints the percent sign when called
 * @param: container of arguments
 * @buffer: Buffer array that handles print
 * @flag: Calculates active flags
 * @wid: this variable gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_per_cent(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	UNUSED(param);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(fmt_prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**** PRINT INT ***********/
/**
 * print_intgrs - Prints integer numbas to the stdout
 * @param: container for lists of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @wid: variable that gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_intgrs(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(param, long int);
	unsigned long int num;

	n = convert_number_size(n, size);

	if (n == 0)
	{
		buffer[j--] = '0';
		
	}

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_digitber(is_negative, j, buffer,
		flag, wid, fmt_prec, size));
}

/***** PRINT BINARY *********/
/**
 * print_bi_nary - Prints an binary numbers in zero's and ones
 * @param: container of list of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @wid: variable that gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_bi_nary(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size)
{
	unsigned int n, m, j, sum;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(fmt_prec);
	UNUSED(size);

	n = va_arg(param, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	arr[0] = n / m;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		arr[j] = (n / m) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += arr[j];
		if (sum || j == 31)
		{
			char wot = '0' + arr[j];

			write(1, &wot, 1);
			count++;
		}
	}
	return (count);
}


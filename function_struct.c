#include "main.h"
 
/************************* PRINT CHAR *************************/
 
/**
 * print_char - Prints a char
 * @param: container of list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that gets width
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	char c = va_arg(param, int);
 
        	return (handle_write_char(c, buffer, flag, wid, fmt_prec, size));
}
 
 
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @param: container of list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
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
                    	if (precision >= 6)
                                	str = "      ";
        	}
 
        	while (str[length] != '\0')
                    	length++;
 
        	if (fmy_prec >= 0 && fmt_prec < length)
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
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @param: container of arguments
 * @buffer: Buffer array that handles print
 * @flag:  Calculates active flags
 * @wid: this variable gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list param, char buffer[],
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
 
/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @param: container for lists of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size)
{
        	int j = BUFF_SIZE - 2;
        	int is_negative = 0;
        	long int n = va_arg(param, long int);
        	unsigned long int num;
 
        	n = convert_number_size(n, size);
 
        	if (n == 0)
                    	buffer[j--] = '0';
 
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
 
        	return (write_number(is_negative, i, buffer, flag, wid, fmt_prec, size));
}
 
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @param: container of list of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: variable that gets width.
 * @fmt_prec: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list param, char buffer[],
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
                    	a[j] = (n / m) % 2;
        	}
        	for (j = 0, sum = 0, count = 0; j < 32; j++)
        	{
                    	sum += arr[j];
                    	if (sum || j == 31)
                    	{
                                	char z = '0' + arr[j];
 
                                	write(1, &z, 1);
                                	count++;
                    	}
        	}
        	return (count);
}


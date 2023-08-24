#include "main.h"
<<<<<<< HEAD
 
void print_buffer(char buffer[], int *buff_idx);
 
=======

>>>>>>> refs/remotes/origin/master
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters, calc.
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
        	int j, printed = 0, calc = 0;
        	int flag, wid, fmt_prec, size, buff_idx = 0;
        	va_list param;
        	char buffer[BUFF_SIZE];
 
        	if (format == NULL)
                    	return (-1);
 
        	va_start(param, format);
 
        	for (j = 0; format && format[j] != '\0'; j++)
        	{
                    	if (format[j] != '%')
                    	{
                                	buffer[buff_ind++] = format[j];
                                	if (buff_idx == BUFF_SIZE)
                                            	print_buffer(buffer, &buff_idx);
                                	/* write(1, &format[j], 1);*/
                                	calc++;
                    	}
                    	else
                    	{
                                	print_buffer(buffer, &buff_idx);
                                	flag = get_flags(format, &j);
                                	wid = get_width(format, &j, param);
                                	fmt_prec = get_precision(format, &j, param);
                                	size = get_size(format, &j);
                                	++j;
                                	printed = trigger_print(format, &j, param, buffer,
                                            	flag, wid, fmt_prec, size);
                                	if (printed == -1)
                                            	return (-1);
                                	calc += printed;
                    	}
        	}
 
        	print_buffer(buffer, &buff_idx);
 
        	va_end(param);
 
        	return (calc);
=======
	va_list param;
	unsigned int ib, calc = 0, str_count;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(param, format);

	for (ib = 0; format[ib] != '\0'; ib++)
	{
		if (format[ib] != '%')
		{
			_putchar(format[ib]);
		}
		else if (format[ib] == '%' && format[ib + 1] == 'c')
		{
			_putchar(va_arg(param, int));
			ib++;
		}
		else if (format[ib + 1] == 's')
		{
			str_count = _putss(va_arg(param, char *));
			ib++;
			calc += (str_count - 1);
		}
		else if (format[ib + 1] == '%')
			_putchar('%');
		calc++;
	}
	va_end(param);
	return (calc);
>>>>>>> refs/remotes/origin/master
}
 /**
 * print_buffer - This function outputs the contents of buffer if it exist
 * @buffer: Array of characters
 * @buff_idx: Index at wch 2 add nxt char also represents the length.
 */
void print_buffer(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);

	*buff_idx = 0;
}


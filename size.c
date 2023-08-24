#include "main.h"
 
/**
 * get_size – This function calculates size given to the argument
 * @format: String that prints arguments
 * @j: container for list of arguments to be printed.
 *
 * Return: size.
 */
int get_size(const char *format, int *j)
{
        	int curr_j = *j + 1;
        	int size = 0;
 
        	if (format[curr_j] == 'l')
                    	size = S_LONG;
        	else if (format[curr_j] == 'h')
                    	size = S_SHORT;
 
        	if (size == 0)
                    	*j = curr_j - 1;
        	else
                    	*j = curr_j;
 
        	return (size);
}

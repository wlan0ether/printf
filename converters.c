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


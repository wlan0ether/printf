#include "main.h"

/**
 * _putss - outputs a string
 * @c: a pointer to a string or char
 * Return: returns the number of bytes or character
 */

int _putss(char *c)
{
	int mib;

	if (c)
	{
		for (mib = 0; c[mib] != '\0'; mib++)
		{
			_putchar(c[mib]);
		}
	}
	return (mib);
}

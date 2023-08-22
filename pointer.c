#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_pointer_address - function that prints the address
 * of any variable
 * @ptr: void pointer
 * @calc: counter to continue iteration in the main printf
 * function
 * Return: void
*/

void print_pointer_address(void *ptr, int *calc)
{
	int mib;
	char buffer[20]; /* this value adjust the buffer size as needed*/

	/*Convert the pointer to hexadecimal string*/
	snprintf(buffer, sizeof(buffer), "%p", ptr);

	for (mib = 0; buffer[mib] != '\0'; mib++)
	{
		_putchar(buffer[mib]);
		(*calc)++;
	}
}

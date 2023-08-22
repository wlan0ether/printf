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
	unsigned long mib;
	int shift;
	int digit;
	char hexChar;
	unsigned long address = (unsigned long)ptr;
	char buffer[50]; /* this value adjust the buffer size as needed*/

	_putchar('0'); /*This prints hexadecimal prefixes '0x'*/
	_putchar('x');
	(*calc) += 2;

	/*manually iterating and converting them to a hexadecimal string*/
	for (mib = 0; mib < sizeof(unsigned long) *2; mib++)
	{
		shift = (sizeof(unsigned long) * 2 - 1 - mib) * 4;
		digit = (address >> shift) & 0xF;
		hexChar = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		_putchar(hexChar);
		(*calc)++;
	}
}

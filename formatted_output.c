#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * @%u: Prints unsigned decimal integers
 * @%o: Prints octal integers
 * @%x: Prints lowercase hexadecimal integers
 * @%X: Prints uppercase hexadecimal integers
 *
 * Return: Always 0 (Success)
 */
int main(showFormattedOutput)
{
	unsigned int unIntValue = 456;
	int octal = 56;
	int hex = 234;

	printf("Unsigned integer: %u\n", unIntValue);
	printf("Octal: %o\n", octal);
	printf("Small Hexvalue: %x\n", hex);
	printf("Large Hexvalue: %X\n", hex);

	return 0;
}

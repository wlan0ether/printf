#include "main.h"

/**
 * call_flag - Function that calculates active flags
 * @format: String that would output the arguments
 * @j: take a parameter.
 * Return: Flags:
 */
int call_flag(const char *format, int *j)
{
	/*various flags in c - + 0 # ' ' */
	/*samw s this  1 2 4 8  16 */
	int bim, curr_j;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_SUB, F_ADD, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (bim = 0; FLAG_CH[bim] != '\0'; bim++)
		{
			if (format[curr_j] == FLAG_CH[bim])
			{
				flag |= FLAG_ARR[bim];
				break;
			}
		}
		if (FLAG_CH[bim] == 0)
			break;
	}

	*j = curr_j - 1;

	return (flag);
}


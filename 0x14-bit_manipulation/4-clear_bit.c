#include "main.h"

/**
 * clear_bit - Clears the bit at the specified index.
 * @n: Represents the number of iterations.
 * @index: Commencing at the rightmost bit
 * Return: either 1 for success or -1 for failure.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	i = ~(1 << index);
	*n = *n & i;

	return (1);
}

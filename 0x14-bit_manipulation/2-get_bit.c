#include "main.h"

/**
 * get_bit - Retrieves the bit value
 * at a specified index.
 * @n: Analyzing the binary data.
 * @index: The bit position to check
 *
 * Return: The state of the bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div, res;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << index;
	res = n & div;
	if (res == div)
		return (1);

	return (0);
}

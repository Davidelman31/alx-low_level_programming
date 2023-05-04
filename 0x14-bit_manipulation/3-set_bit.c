#include "main.h"

/**
 * set_bit - sets the bit at the specified index to 1.
 * @index: Specify the bit position, starting at 0.
 * @n: Pointer to the element at index i.
 * Return: Returns 1 upon success, -1 upon failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	i = 1 << index;
	*n = *n | i;

	return (1);
}

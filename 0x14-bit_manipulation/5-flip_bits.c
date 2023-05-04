#include "main.h"
/**
 * flip_bits - bitwise complement operation to transform
 * one number into another.
 * @n: the first operand
 * @m: the second operand
 * Return: Returns minimum flips for input conversion.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int differnce, result;
	unsigned int j, i;

	j = 0;
	result = 1;
	differnce = n ^ m;
	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if (result == (differnce & result))
			j++;
		result <<= 1;
	}

	return (j);
}

#include "main.h"

/**
 * _memset - To fill n bytes of memory with a constant value
 * @s: input pointer to memory area
 * @b: input constant value
 * @n: number of bytes to fill
 * Return: Always 0 for Success
 */

char *_memset(char *s, char b, unsigned int n)
{

	int size = n;

	/* Only Positive sizes */
	if (size > 0)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			s[i] = b;
		}
	}
	return (s);
}

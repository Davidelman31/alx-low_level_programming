#include "main.h"
/**
 * _memset - fills  block of mem with a specific value.
 * @s: initial address of memory to fill.
 * @b: the  value.
 * @n: number of bytes to change.
 *
 * Return: array replaced by new value for n bytes.
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;


	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}

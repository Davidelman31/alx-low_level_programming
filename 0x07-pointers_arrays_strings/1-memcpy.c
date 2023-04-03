#include "main.h"

/**
 * _memcpy - Entry point which copies the main area
 * @dest: This is the buffer where we will copy
 * @src: this is what we are meant to copy
 * @n: bytes
 * Return: Always 0 (Success)
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

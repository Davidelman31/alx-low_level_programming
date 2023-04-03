#include <stdio.h>
#include "main.h"

/**
 * _strpbrk - Is a function that searches for strings
 * @s: is a pointer to the input string
 * @accept: input pointer for the string searching for in @s
 * Return: Always 0 (Success)
 */

char *_strpbrk(char *s, char *accept)
{
	int i, n;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (n = 0; accept[n] != '\0'; n++)
		{
			if (s[i] == accept[n])
				return (s + i);
		}
	}

	return (NULL);
}

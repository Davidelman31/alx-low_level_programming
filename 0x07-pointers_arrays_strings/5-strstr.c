#include <stdio.h>
#include "main.h"

/**
 * _strstr - Function that will locate the substring
 * @haystack: whill search for matching substrings
 * @needle: what to be searched
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *one = haystack;
		char *two = needle;

		while (*one == *two && *two != '\0')
		{
			one++;
			two++;
		}

		if (*two == '\0')
			return (haystack);
	}

	return (NULL);
}

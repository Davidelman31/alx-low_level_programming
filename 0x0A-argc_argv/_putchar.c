#include <stdio.h>
#include "main.h"

/**
 * _putchar - fxn to write the character c to stdout.
 * @c:The character to be printed.
 *
 * Return: 1 on Success.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

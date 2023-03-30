#include <unistd>

/**
 * _putchar - writes the charcter c to stdout
 * @c: The character to print
 *
 * Retuurn: On sucess1.
 * On error, -1 is returned, and errno is set appropriatly.
 */
int _putchar()char c
{
	return (write(1, &c, 1));
}

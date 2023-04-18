#include <stdio.h>

/**
 * main - fxn printing number of arguments passed into it.
 * @argc: arguments count.
 * @argv: arguments.
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}

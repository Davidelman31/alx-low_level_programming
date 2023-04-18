#include <stdio.h>

/**
 * main -  prints the number of args passed into it.
 * @argc: argument counts.
 * @argv: arguments.
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}

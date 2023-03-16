#include <stdio.h>
/**
 * main - A program that prints the size of various computer data types
 * Return: 0 (Success)
 */
int main(void)
{
        char a;
	int b;
	long int c;
	long long int d;
	float f;
printf("Size of a char: %lu byte(s)\n", (char)sizeof(a));
printf("Size of a int: %lu byte(s)\n", (int)sizeof(b));
printf("Size of a long int: %lu bytes(s)\n", (long int)sizeof(c));
printf("Size of a long long int: %lu bytes(s)\n", (long long int)sizeof(d));
printf("Size of a float: %d byte(s)\n", (float)sizeof(f));
return (0);
}

#include "main.h"

/**
  * factorial -  a function that returns the factorial of a given number.
  * @n: is the number to calculate the factorial.
  * Return: integer valu.e
  */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n <= 1)
		return (1);

	return (n * factorial(n - 1));
}

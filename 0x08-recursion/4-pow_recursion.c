#include "main.h"

/**
  * _pow_recursion - Returns the value of x raised to y.
  * @x: is the value to multiply
  * @y: is times to multiply the number.
  *
  * Return: the value multiplied y times
  */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}

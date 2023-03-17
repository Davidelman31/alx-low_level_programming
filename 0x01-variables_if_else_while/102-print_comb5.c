#include <stdio.h>

<<<<<<< HEAD
/*
 * main - Prints all possibles combinations of two-digit numbers.
 * Return: Always 0 (Suuccess)
=======
/**
 * main - Prints all possible combinations of two-digit numbers.
 * Return: Always 0 (Success)
>>>>>>> 792379c4092957c3b45473d35329bb68306388d1
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (i < j)
			{
				putchar((i / 10) + 48);
				putchar((i % 10) + 48);
				putchar(' ');
				putchar((j / 10) + 48);
				putchar((j % 10) + 48);
				if (i != 98 || j != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

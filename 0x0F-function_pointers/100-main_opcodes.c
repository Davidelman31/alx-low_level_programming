#include <stdio.h>
#include <stdlib.h>

/**
* main - prints the opcodes of its own main function.
* @argc: the number of arguments.
* @argv: A pointer to an array of
* command-line arguments.
* Return: 0 on success, 1 on wrong number of arguments, 
* 2 on negative number of bytes
*/
int main(int argc, char **argv)
{
int bytes, i;

if (argc != 2)
{
printf("Error\n");
return (1);
}

bytes = atoi(argv[1]);

if (bytes < 0)
{
printf("Error\n");
return (2);
}

for (i = 0; i < bytes; i++)
{
printf("%02x", *((unsigned char *)main + i));
if (i == bytes - 1)
printf("\n");
else
printf(" ");
}

return (0);
}

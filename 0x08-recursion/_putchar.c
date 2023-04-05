#include <unistd.h>

/**
* This is _putchar.c file.
*/

int _putchar(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}


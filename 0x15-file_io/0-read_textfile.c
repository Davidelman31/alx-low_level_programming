#include "main.h"
#include <stdlib.h>

/**
 * read_textfile-Display the contents of the text
 * file on the console
 * @filename: text file parsed
 * @letters: number of characterss to be read
 * Return: The function returns the number
 * of bytes read and printed on success,
 * or 0 if the filename is NULL or if an error
 * occurs during the operation
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}


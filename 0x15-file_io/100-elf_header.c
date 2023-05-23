#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * custom_strncmp - Perform a comparison of two strings.
 * @s1: string reps the first value
 * @s2: string reps the second value
 * @n: the predetermined byte count for comparison.
 *
 * Return: 0 for identical first n bytes of s1 and s2, otherwise a non-zero value.
 */
int custom_strncmp(const char *s1, const char *s2, size_t n)
{
    for (; n && *s1 && *s2; --n, ++s1, ++s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
    }
    if (n && *s1)
        return (1);
    if (n && *s2)
        return (-1);
    return (0);
}

/**
 * custom_close - terminates file descriptor and displays error message if unsuccessful
 * @fd: The file handle to close
 */
void custom_close(int fd)
{
    if (close(fd) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't close file descriptor\n", 35);
    exit(98);
}

/**
 * custom_read - Attempt to read from a file then handles errors if encountered
 * @fd:  source file descriptor
 * @buf: the destination buffer
 * @count: the size of the data to be read in bytes
 */
void custom_read(int fd, char *buf, size_t count)
{
    if (read(fd, buf, count) != -1)
        return;
    write(STDERR_FILENO, "Error: Can't read from file\n", 28);
    custom_close(fd);
    exit(98);
}

/**
 * print_elf_magic - print ELF magic.
 * @buffer: Header data in the ELF file
 */
void print_elf_magic(const unsigned char *buffer)
{
    unsigned int i;
    if (custom_strncmp((const char *)buffer, ELFMAG, 4))
    {
        write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
        exit(98);
    }
    printf("ELF Header:\n  Magic:   ");
    for (i = 0; i < 16; ++i)
        printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}

/**
 * print_elf_class - print ELF class
 * @buffer: Header data in the ELF file
 *
 * Return: Bit architecture (32-bit or 64-bit)
 */
size_t print_elf_class(const unsigned char *buffer)
{
    printf("  %-34s ", "Class:");
    if (buffer[EI_CLASS] == ELFCLASS64)
    {
        printf("ELF64\n");
        return (64);
    }
    if (buffer[EI_CLASS] == ELFCLASS32)
    {
        printf("ELF32\n");
        return (32);
    }
    printf("<unknown: %x>\n", buffer[EI_CLASS]);
    return (32);
}

/**
 * print_elf_data - displays ELF data
 * @buffer: ELF header segment.
 *
 * Return: 1 big endian, 0 little endian byte order explanation
 */
int print_elf_data(const unsigned char *buffer)
{
    printf("  %-34s ", "Data:");
    if (buffer[EI_DATA] == ELFDATA2MSB)
    {
        printf("2's complement, big endian\n");
        return (1);
    }
    if (buffer[EI_DATA] == ELFDATA2LSB)
    {
        printf("2's complement, little endian\n");
        return (0);
    }
    printf("<unknown: %x>\n", buffer[EI_DATA]);
    return (0);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr *header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        dprintf(STDERR_FILENO, "Error: No memory available\n");
        custom_close(fd);
        exit(98);
    }
    custom_read(fd, (char *)header, sizeof(Elf64_Ehdr));
    print_elf_magic(header->e_ident);
    print_elf_class(header->e_ident);
    print_elf_data(header->e_ident);
    free(header);
    custom_close(fd);
    return (0);
}

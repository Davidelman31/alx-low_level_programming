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
    if (n)
    {
        if (*s1)
            return (1);
        if (*s2)
            return (-1);
    }
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
    printf("Invalid data encoding\n");
    return (0);
}

/**
 * print_elf_version - Output ELF version
 * @buffer: The header of the ELF file.
 */
void print_elf_version(const unsigned char *buffer)
{
    printf("  %-34s %u", "Version:", buffer[EI_VERSION]);

    if (buffer[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}

/**
 * print_elf_osabi - Display ELF Operating System/ABI
 * @buffer: The header of the ELF file.
 */
void print_elf_osabi(const unsigned char *buffer)
{
    const char *os_table[19] = {
        "UNIX - System V",
        "UNIX - HP-UX",
        "UNIX - NetBSD",
        "UNIX - GNU",
        "<unknown: 4>",
        "<unknown: 5>",
        "UNIX - Solaris",
        "UNIX - AIX",
        "UNIX - IRIX",
        "UNIX - FreeBSD",
        "UNIX - Tru64",
        "Novell - Modesto",
        "UNIX - OpenBSD",
        "VMS - OpenVMS",
        "HP - Non-Stop Kernel",
        "AROS",
        "FenixOS",
        "Nuxi CloudABI",
        "Stratus Technologies OpenVOS"
    };

    printf("  %-34s ", "OS/ABI:");

    if (buffer[EI_OSABI] < 19)
        printf("%s\n", os_table[(unsigned int)buffer[EI_OSABI]]);
    else
        printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * print_elf_abivers - Output ELF ABI version
 * @buffer: The header of the ELF file.
 */
void print_elf_abivers(const unsigned char *buffer)
{
    printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * print_elf_type - Outputs ELF type
 * @buffer: The header of the ELF file.
 * @big_endian: Endian representation (big endian for non-zero values).
 */
void print_elf_type(const unsigned char *buffer, int big_endian)
{
    char *type_table[5] = {
        "NONE (No file type)",
        "REL (Relocatable file)",
        "EXEC (Executable file)",
        "DYN (Shared object file)",
        "CORE (Core file)"
    };
    unsigned int type;

    printf("  %-34s ", "Type:");

    if (big_endian)
        type = 0x100 * buffer[16] + buffer[17];
    else
        type = 0x100 * buffer[17] + buffer[16];

    if (type < 5)
        printf("%s\n", type_table[type]);
    else if (type >= ET_LOOS && type <= ET_HIOS)
        printf("OS Specific: (%4x)\n", type);
    else if (type >= ET_LOPROC && type <= ET_HIPROC)
        printf("Processor Specific: (%4x)\n", type);
    else
        printf("<unknown: %x>\n", type);
}

/**
 * print_elf_entry - Display the entry point address.
 * @buffer: Address-containing string for the entry point
 * @bit_mode: Architecture (32-bit or 64-bit)
 * @big_endian: Endian representation (big endian for non-zero values).
 */
void print_elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian)
{
    int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (address_size && !*(buffer))
			--address_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += address_size;

		while (address_size && !*(--buffer))
			--address_size;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

/**
 * main - Clone the file's content into another file.
 * @argc: Total number of arguments
 * @argv: the input parameters
 *
 * Return: Consistently zero
 */
int main(int argc, const char *argv[])
{
	unsigned char buffer[18];
	unsigned int bit_mode;
	int big_endian;
	int fd;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	_read(fd, (char *) buffer, 18);

	elf_magic(buffer);
	bit_mode = elf_class(buffer);
	big_endian = elf_data(buffer);
	elf_version(buffer);
	elf_osabi(buffer);
	elf_abivers(buffer);
	elf_type(buffer, big_endian);

	lseek(fd, 24, SEEK_SET);
	_read(fd, (char *) buffer, bit_mode / 8);

	elf_entry(buffer, bit_mode, big_endian);

	_close(fd);

	return (0);
}

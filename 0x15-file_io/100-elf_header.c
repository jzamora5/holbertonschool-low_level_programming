#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void _class(char *h, int x64);
void _data(char *h);
void _version(char *h);
void _os(char *h);
void _type(char *h, int x64);
void _entry(char *h, int x64);

/**
 * main - displays the information contained in the ELF header at
 * the start of an ELF file.
 *
 * Usage: elf_header elf_filename
 * displayed information: (not less, not more)
 * Magic
 * Class
 * Data
 * Version
 * OS/ABI
 * ABI Version
 * Type
 * Entry point address
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 *
 * Return: Always 0 on (Success)
 *
 * if the file is not an ELF file, or on error, exit with status code 98
 *  and display a comprehensive error message to stderr
 */
int main(int argc, char **argv)
{
	int i, fdelf, relf, closecheck, x64 = 0;
	char h[32];

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

	fdelf = open(argv[1], O_RDONLY);
	if (fdelf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	relf = read(fdelf, h, 32);
	if (relf == -1)
		dprintf(STDERR_FILENO, "Error Reading File\n"), exit(98);

	if (h[0] != 0x7f || h[1] != 'E' || h[2] != 'L' || h[3] != 'F')
		dprintf(STDERR_FILENO, "Error: Wrong file type\n"), exit(98);

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < 16; i++)
		printf("%02x ", (unsigned int)h[i]);
	printf("\n");

	if (h[4] == 2)
		x64 = 1;

	_class(h, x64);
	_data(h);
	_version(h);
	_os(h);

	printf("  %-35s0\n", "ABI Version:");

	_type(h, x64);
	_entry(h, x64);

	closecheck = close(fdelf);
	if (closecheck == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdelf), exit(98);

	return (0);
}

/**
 * _class - print elf class
 *
 * @h: header
 * @x64: 1 if x64, 0 if x32
 *
 * Return: No Return
 */
void _class(char *h, int x64)
{
	if (h[4] != 1 && h[4] != 2)
	{
		printf("<unknown: %02hx>\n", h[4]);
		return;
	}
	printf("  %-35s", "Class:");
	if (x64 == 0)
		printf("ELF32\n");
	else if (x64 == 1)
		printf("ELF64\n");
}
/**
 * _data - print elf data
 *
 * @h: header
 *
 * Return: No Return
 */
void _data(char *h)
{
	printf("  %-35s", "Data:");
	printf("2's complement, ");
	if (h[5] == 1)
		printf("little endian\n");
	else if (h[5] == 2)
		printf("big endian\n");
	else
		printf("<unknown: %02hx>\n", h[5]);
}
/**
 * _version - print elf version
 *
 * @h: header
 *
 * Return: No Return
 */
void _version(char *h)
{
	printf("  %-35s", "Version:");
	if (h[6] == 1)
		printf("1 (current)\n");
	else if (h[5] == 0)
		printf("0 (invalid)\n");
	else
		printf("<unknown: %02hx>\n", h[6]);
}
/**
 * _os - print elf os/ABI
 *
 * @h: header
 *
 * Return: No Return
 */
void _os(char *h)
{
	printf("  %-35s", "OS/ABI:");

	switch (h[7])
	{
	case 0:
		printf("UNIX - System V\n");
		break;
	case 1:
		printf("UNIX - HP-UX\n");
		break;
	case 2:
		printf("UNIX - NetBSD\n");
		break;
	case 3:
		printf("UNIX - Linux\n");
		break;
	case 4:
		printf("UNIX - GNU Hurd\n");
		break;
	case 6:
		printf("UNIX - Solaris\n");
		break;
	case 7:
		printf("UNIX - AIX\n");
		break;
	case 8:
		printf("UNIX - IRIX\n");
		break;
	case 9:
		printf("UNIX - FreeBSD\n");
		break;
	case 10:
		printf("UNIX - Tru64\n");
		break;
	case 11:
		printf("UNIX - Novell Modesto\n");
		break;
	case 12:
		printf("UNIX - OpenBSD\n");
		break;
	case 13:
		printf("UNIX - Open VMS\n");
		break;
	case 14:
		printf("UNIX - NonStop Kernel\n");
		break;
	case 15:
		printf("UNIX - AROS\n");
		break;
	case 16:
		printf("UNIX - Fenix OS\n");
		break;
	case 17:
		printf("UNIX - CloudABI\n");
		break;
	default:
		printf("<unknown: %02hx>\n", h[7]);
		break;
	}

}
/**
 * _type - print elf type
 *
 * @h: header
 * @x64: variable to check if x64 (1) or x32 (0)
 *
 * Return: No Return
 */
void _type(char *h, int x64)
{
	int xtype;

	if (x64 == 0)
		xtype = 16;
	else
		xtype = 17;

	printf("  %-35s", "Type:");

	switch (h[xtype])
	{
	case 0:
		printf("NONE\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown>: %02x%02x\n", h[16], h[17]);
	}

}
/**
 * _entry - print elf entry point access by directly accesing
 * the elf header struct
 *
 * @h: header
 * @x64: check 1 for x64 and 0 x32
 *
 * Return: No Return
 */
void _entry(char *h, int x64)
{
	int count, i;

	printf("  %-35s0x", "Entry point address:");

	if (x64 == 0)
		count = 24 + 4;
	else if (x64 == 1)
		count = 24 + 8;

	if (h[5] == 1)
	{
		/* Little Endian */
		for (i = count - 1; i >= 24; i--)
			if (h[i] != 0)
				printf("%02x", (unsigned char) h[i]);
	}
	else
	{
		/* Big Endian */

		for (i = 24; i < count; i++)
			if (h[i] != 0)
				printf("%02x", (unsigned char) h[i]);
	}
	printf("\n");
}
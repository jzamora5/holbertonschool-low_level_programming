#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - program that copies the content of a file to another file
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 * Return: Always 0 on (Success)
 *
 * if the number of argument is not the correct one, exit with code 97
 * and print Usage: cp file_from file_to, followed by a new line,
 * on the POSIX standard error
 *
 * if file_from does not exist, or if you can not read it, exit with
 * code 98 and print Error: Can't read from file NAME_OF_THE_FILE,
 * followed by a new line, on the POSIX standard error
 *
 * if you can not close a file descriptor ,
 * exit with code 100 and print Error:
 * Can't close fd FD_VALUE, followed by a new line,
 * on the POSIX standard error
 */
int main(int argc, char **argv)
{
	int fdfrom, fdto, checkr, checkw, checkc1, checkc2;
	char buff[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	fdfrom = open(argv[1], O_RDONLY);
	if (fdfrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fdto = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdto == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);


	while ((checkr = read(fdfrom, buff, 1024)) > 0)
	{
		checkw = write(fdto, buff, checkr);
		if (checkw != checkr)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (checkr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	checkc1 = close(fdfrom);
	if (checkc1 == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdfrom), exit(100);
	checkc2 = close(fdto);
	if (checkc2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdto), exit(100);

	return (0);
}

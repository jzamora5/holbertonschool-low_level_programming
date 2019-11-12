#include "holberton.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - creates a file
 *
 * @filename: name of the file
 * @text_content: NULL terminated string to write to the file
 *
 * Return: Returns: 1 on success, -1 on failure
 * file can not be created, file can not be written, write “fails”, etc…
 * The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	int fd, checkw, l = 0;

	if (filename == 0)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[l] != 0)
			l++;
		checkw = write(fd, text_content, l);

		if (checkw == -1 || checkw != l)
			return (-1);
	}

	close(fd);
	return (1);
}

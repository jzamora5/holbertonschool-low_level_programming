#include "holberton.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: memory area destination
 * @src: memory area source
 * @n: n bytes of memory area to be copied
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++, dest++, src++)
		*dest = *src;
	dest = dest - n;
	return (dest);
}

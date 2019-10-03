#include "holberton.h"

/**
 * _strncat - concatenates two strings using most n bytes
 * @dest: string 1
 * @src: strint 2
 * @n: n bytes from from src
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j, k;

	i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (n < j)
		j = n - 1;
	for (k = 0; k <= j; k++, i++)
		dest[i] = src[k];
	dest[i + 1] = '\0';
	return (dest);
}

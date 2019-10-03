#include "holberton.h"

/**
 * _strcat - concatenates two strings
 * @dest: string 1
 * @src: strint 2
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k;

	i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	for (k = 0; k <= j; k++, i++)
		dest[i] = src[k];
	return (dest);
}

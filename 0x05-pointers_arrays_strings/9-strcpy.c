#include "holberton.h"
#include <stdio.h>

/**
 * _strcpy - copies one string to another
 * @dest: Array
 * @src: Size of Array
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = *(src + j);
	}
	return (dest);
}

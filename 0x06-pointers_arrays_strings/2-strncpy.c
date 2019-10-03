#include "holberton.h"

/**
 * _strncpy - copies n bytes of one string to another
 * @dest: string destination
 * @src: strint source
 * @n: n bytes from from src
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, k;

	i = 0;
	while (src[i] != '\0')
		i++;
	for (k = 0; k < n; k++)
	{
		if (k < i)
		{
			dest[k] = src[k];
		}
		else if (k >= i)
		{
			dest[k] = 0;
		}
	}
	return (dest);
}

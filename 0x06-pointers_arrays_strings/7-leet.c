#include "holberton.h"
#include <stdio.h>
/**
 * leet - encodes string to 1337
 * @s: string to encode
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *leet(char *s)
{
	int i, j;
	char leet[] = "aeotl";
	char leet2[] = "AEOTL";
	char leet3[] = "43071";

	j = 0;
	while (*s != 0)
	{
		for (i = 0; i <= 4; i++)
		{
			if (*s == leet[i] || *s == leet2[i])
				*s = leet3[i];
		}
		s++;
		j++;
	}
	s = s - j;
	return (s);
}

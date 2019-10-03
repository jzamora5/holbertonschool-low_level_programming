#include "holberton.h"
#include <stdio.h>
/**
 * rot13 - encodes string to rot13
 * @s: string to encode
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *rot13(char *s)
{
	int i, j;
	char rot13a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	j = 0;
	while (s[j] != 0)
	{
		for (i = 0; i < 52; i++)
		{
			if (s[j] == rot13a[i])
			{
				s[j] = rot13b[i];
				break;
			}
		}
		j++;
	}
	return (s);
}

#include "holberton.h"

/**
 * _strstr - finds the first occurrence of the substring needle in haystack
 * @haystack: string where to look
 * @needle: string to find
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strstr(char *haystack, char *needle)
{
	int l, l2, i, j, c = 0;

	l = 0, l2 = 0, c = 0;
	while (haystack[l] != '\0')
		l++;
	while (needle[l2] != '\0')
		l2++;
	for (i = 0; i < l; i++, haystack++)
	{
		for (j = 0, c = 0; j < l2; j++)
		{
			if (haystack[j] == 0)
				break;
			if (haystack[j] == needle[j])
			{
				c += 1;
			}
		}
		if (c == l2)
			break;
	}
	return (haystack);
}

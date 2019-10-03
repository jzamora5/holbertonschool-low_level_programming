#include "holberton.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: strint 2
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _strcmp(char *s1, char *s2)
{
	int i, j, k, l, v;

	i = 0, j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (i >= j)
		k = i;
	else
		k = j;
	for (l = 0; l <= k; l++)
	{
		if ((s1[l] == 0) && (s2[l] != 0))
		{
			v = -15;
			break;
		}
		else if ((s2[l] == 0) && (s1[l] != 0))
		{
			v = 15;
			break;
		}
		else if ((s1[l] == 0) && (s2[l] == 0))
		{
			v = 0;
			break;
		}
	}
	return (v);
}

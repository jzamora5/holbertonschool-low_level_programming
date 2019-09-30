#include "holberton.h"
#include <stdio.h>
/**
 * rev_string - reverses a string
 * @s: string
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void rev_string(char *s)
{
	int i, j, l;
	char tmp;

	i = 0;
	j = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	l = i / 2;
	i = i - 1;
	while (i >= l)
	{
		tmp  = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--;
		j++;
	}
}

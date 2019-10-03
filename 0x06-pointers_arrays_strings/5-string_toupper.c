#include "holberton.h"
#include <stdio.h>
/**
 * string_toupper - changes lowercase letters to uppercase in string
 * @s: string to change
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *string_toupper(char *s)
{
	int i, j;

	i = 0;
	while (s[i] != '\0')
		i++;
	for (j = 0; j < i; j++)
	{
		if ((s[j] >= 97) && (s[j] <= 122))
			s[j] = s[j] - 32;
	}
	return (s);
}

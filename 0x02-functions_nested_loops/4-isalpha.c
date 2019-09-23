#include "holberton.h"

/**
 * _isalpha - returns 1 if its alphabetic character, 0 otherwise
 * @c: Input parameter in ASCII
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _isalpha(int c)
{
	int i;

	if (((c > 96) && (c < 123)) || ((c > 64) && (c < 91)))
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}

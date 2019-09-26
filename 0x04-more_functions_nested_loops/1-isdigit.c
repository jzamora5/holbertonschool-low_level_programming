#include "holberton.h"

/**
 * _isdigit - returns 1 if digit, 0 otherwise
 * @c: Input parameter in ASCII
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _isdigit(int c)
{
	int i;

	if ((c > 47) && (c < 58))
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}

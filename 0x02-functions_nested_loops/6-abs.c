#include "holberton.h"

/**
 * _abs - returns absolute value of a number
 * @n: An integer number
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _abs(int n)
{
	int i;

	if (n < 0)
	{
		i = n * -1;
	}
	else
	{
		i = n;
	}
	return (i);
}

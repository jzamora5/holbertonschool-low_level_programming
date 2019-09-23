#include "holberton.h"
#include <unistd.h>

/**
 * _islower - returns 1 is lowercase, 0 otherwise
 * @c: Input parameter in ASCII
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _islower(int c)
{
	int i;

	if ((c > 96) && (c < 123))
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}

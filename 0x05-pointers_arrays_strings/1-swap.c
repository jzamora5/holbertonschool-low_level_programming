#include "holberton.h"

/**
 * swap_int - swaps two values
 * @a: integer pointer
 * @b: integer pointer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void swap_int(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
}

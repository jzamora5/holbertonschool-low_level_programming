#include "holberton.h"
#include <stdio.h>

/**
 * print_array - prints array
 * @a: Array
 * @n: Size of Array
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%i, ", a[i]);
		else
			printf("%i\n", a[i]);
	}
}

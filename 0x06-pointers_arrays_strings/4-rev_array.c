#include "holberton.h"
#include <stdio.h>
/**
 * reverse_array - reverses a string
 * @a: array
 * @n: number of elements in array
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void reverse_array(int *a, int n)
{
	int j, l;
	int tmp;

	j = 0;
	l = n / 2;
	n = n - 1;
	while (n >= l)
	{
		tmp  = a[j];
		a[j] = a[n];
		a[n] = tmp;
		n--;
		j++;
	}
}

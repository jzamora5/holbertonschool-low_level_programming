#include "holberton.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of
 * a square matrix of integers
 *
 * @a: matrix
 * @size: size of matrix
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_diagsums(int *a, int size)
{
	int i, j, sum;

	for (i = 0, j = 0, sum = 0; i < size; i++, j += size)
		sum += *(a + (i + j));
	printf("%i, ", sum);
	for (i = 0, j = size - 1, sum = 0; i < size; i++, j += size - 2)
		sum += *(a + (i + j));
	printf("%i\n", sum);

}

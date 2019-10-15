#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: columns
 * @height: rows
 *
 * Return: Double Pointer
 */
int **alloc_grid(int width, int height)
{
	int **s, i;

	if (width <= 0 || height <= 0)
		return (0);

	s = calloc(height, sizeof(int *));
	if (s == 0)
		return (0);
	for (i = 0; i < height; i++)
	{
		*(s + i) = calloc(width, sizeof(int));
		if (*(s + i) == 0)
			return (0);
	}
	return (s);
}

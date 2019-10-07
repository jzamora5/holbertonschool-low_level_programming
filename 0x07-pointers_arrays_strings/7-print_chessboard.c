#include "holberton.h"

/**
 * print_chessboard - prints a chessboard
 * @a: matrix
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_chessboard(char (*a)[8])
{
	int i, j, size;

	size = 8;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}

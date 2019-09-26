#include "holberton.h"

/**
 * print_line - prints a line
 * @n: Determines how long the line will be
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_line(int n)
{
	int i;

	if (n < 1)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}

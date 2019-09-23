#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, n, m, c;

	c = 0;
	for (i = 0; i < 1024; i++)
	{
		n = i % 5;
		m = i % 3;
		if ((n == 0) || (m == 0))
		{
			c = c + i;
		}
	}
	printf("%i\n", c);
	return (0);
}

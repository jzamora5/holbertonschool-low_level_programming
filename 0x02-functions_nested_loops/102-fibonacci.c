#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, n, m, c, u;

	n = 1;
	m = 2;
	u= 48;
	printf("%i, ", n);
	printf("%i, ", m);
	for (i = 1; i <= u; i++)
	{
		c = m + n;
		n = m;
		m = c;
		if (i != u)
		{
			printf("%i, ", c);
		}
		else
		{
			printf("%i\n", c);
		}
	}
	return (0);
}

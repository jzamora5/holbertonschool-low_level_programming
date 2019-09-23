#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int i, n, m, c, u;

	n = 1;
	m = 2;
	u= 48;
	printf("%li, ", n);
	printf("%li, ", m);
	for (i = 1; i <= u; i++)
	{
		c = m + n;
		n = m;
		m = c;
		if (i != u)
		{
			printf("%li, ", c);
		}
		else
		{
			printf("%li\n", c);
		}
	}
	return (0);
}

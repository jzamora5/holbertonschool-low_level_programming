#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n, m, c, e, l;

	n = 1;
	m = 2;
	e = 2;
	l = 4000000;
	c = 0;
	while (c <= l)
	{
		c = m + n;
		n = m;
		m = c;
		if ((c % 2 == 0) && (c <= l))
		{
			e = e + c;
		}
	}
	printf("%li\n", e);
	return (0);
}

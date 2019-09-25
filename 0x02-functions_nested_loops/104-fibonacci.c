#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a, b, c, d, m, n, z;
	unsigned long int split1, split2, digit, thousand, cycl, limit;

	m = 1;
	n = 2;
	limit = 96;
	digit = 1000;
	printf("%lu, ", m);
	printf("%lu, ", n);
	for (cycl = 1; cycl <= 90; cycl++)
	{
		z = m + n;
		m = n;
		n = z;
		printf("%lu, ", z);
	}
	a = m / digit, b = m % digit;
	c = n / digit, d = n % digit;
	for (cycl = 91; cycl <= limit; cycl++)
	{
		thousand = (b + d) / digit;
		split1 = (a + c) + thousand;
		split2 = (b + d) - thousand * digit;
		a = c, b = d;
		c = split1, d = split2;
		if (split2 >= 100)
			printf("%lu%lu", split1, split2);
		else
			printf("%lu0%lu", split1, split2);
		if (cycl != limit)
			printf(", ");
	}
	putchar('\n');
	return (0);
}

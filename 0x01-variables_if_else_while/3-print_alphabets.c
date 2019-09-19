#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 97, m = 65;

	while (n < 123)
	{
		putchar(n);
		n++;
	}
	while (m < 91)
	{
		putchar(m);
		m++;
	}
	putchar('\n');
	return (0);
}

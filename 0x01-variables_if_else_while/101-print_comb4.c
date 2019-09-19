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
	int n = 48;
	int m = 49;
	int w = 50;
	int c = 49;
	int d = 50;
	int b = 50;

	while (n < 58)
	{
		while (m < 58)
		{
			while (w < 58)
			{
				putchar(n);
				putchar(m);
				putchar(w);
				if ((n != 56) || (m != 57) || (w != 58))
				{
					putchar(44);
					putchar(32);
				}
				w++;
			}
			m++;
			d++;
			w = d;
		}
		c++;
		b++;
		d = b;
		m = c;
		w = b;
		n++;
	}

	putchar('\n');
	return (0);
}

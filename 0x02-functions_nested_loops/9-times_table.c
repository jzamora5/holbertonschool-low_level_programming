#include "holberton.h"

/**
 * times_table - prints the 9 times table starting with 0
 * void: No return
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void times_table(void)
{
	int i, j, n;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			n = i * j;
			if (n > 9)
			{
				if (j != 0)
				{
					_putchar(44);
					_putchar(32);
				}
				_putchar('0' + n / 10);
				_putchar('0' + n % 10);
			}
			else
			{
				if (j != 0)
				{
					_putchar(44);
					_putchar(32);
					_putchar(32);
				}
				_putchar('0' + n);
			}
		}
		_putchar('\n');
	}
}

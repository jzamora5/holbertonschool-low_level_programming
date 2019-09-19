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
	int i, j;
	int array[4];
	int A;
	int B;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (i != j)
			{
				array[0] = i / 10;
				array[1] = i % 10;
				array[2] = j / 10;
				array[3] = j % 10;
				A = i * 100 + j;
				B = j * 100 + i;

				if (A < B)
				{
					putchar(array[0] + '0');
					putchar(array[1] + '0');
					putchar(32);
					putchar(array[2] + '0');
					putchar(array[3] + '0');
					if ((i != 98) || (j != 99))
					{
						putchar(44);
						putchar(32);
					}
				}
			}

		}
	}
	putchar('\n');
	return (0);
}

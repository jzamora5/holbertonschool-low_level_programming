#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, count, limit, upper, lower;
	char s;

	count = 0;
	limit = 2772;
	lower = 32;
	upper = 126;
	while ((limit - count) > 0)
	{
		srand(time(0) + count);
		n = (rand() % (upper - lower + 1)) + lower;
		if ((count + n) <= limit)
		{
			s = n;
			printf("%c", s);
			count = count + n;
		}
		else
		{
			break;
		}
	}
	if ((limit - count) > 0)
	{
		n = limit - count;
		s = n;
		printf("%c", s);
	}
	return (0);
}

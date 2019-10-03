#include "holberton.h"
#include <stdio.h>
/**
 * infinite_add - adds two numbers
 * @n1: number 1
 * @n2: number 2
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, diff, big, small, cyc, cyc2, count, tmp, ten, check;
	char *less, *more;

	i = 0, j = 0;
	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	if (i >= j)
		big = i, small = j, diff = i - j + 1, less = n2, more = n1;
	else
		big = j, small = i, diff = j - i + 1, less = n1, more = n2;
	count = 0, cyc = diff, ten = 0;
	for (count = 0; count < small; count++, cyc++)
		r[cyc] = less[count];
	for (cyc2 = big; cyc2 >= 1; cyc2--)
	{
		if (cyc > size_r - 1)
			return (0);
		if (r[cyc2] <= 57 && r[cyc2] >= 48)
			tmp = (r[cyc2] - '0') + (more[cyc2 - 1] - '0') + ten;
		else
			tmp = (more[cyc2 - 1] - '0') + ten;
		ten = tmp / 10;
		tmp = tmp - (ten * 10);
		r[cyc2] = '0' + tmp;
	}
	r[cyc2] = '0' + ten;
	if (ten == 0)
		r++;
	for (check = 0; check < size_r; check++)
		if (r[check] > 57 || r[check] < 48)
			r[check] = 0;
	return (r);
}

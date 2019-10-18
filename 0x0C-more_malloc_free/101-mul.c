#include <stdio.h>
#include <stdlib.h>
/**
 * _callocX -  malloc with 0 initialization
 * @nmemb: initial adress
 *
 * Return: Return pointer with reserved memory in 0
 */
char *_callocX(unsigned int nmemb)
{
	unsigned int i;
	char *p;

	p = malloc(nmemb + 1);
	if (p == 0)
		return (0);
	for (i = 0; i < nmemb; i++)
		p[i] = '0';
	p[i] = '\0';
	return (p);
}
/**
 * _isdigit -  checks if character is digit
 * @c: character
 *
 * Return: Return pointer char (so movements are 1 byte)
 */
int _isdigit(char c)
{
	int i;

	if ((c > 47) && (c < 58))
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}
/**
 * _isnumber -  checks if string is number
 * @s: string
 *
 * Return: Return length
 */
int _isnumber(char *s)
{
	int i, check, d;

	d = 0, check = 1;
	for (i = 0; *(s + i) != 0; i++)
	{
		d = _isdigit(*(s + i));
		if (d == 0)
		{
			check = 0;
			break;
		}
	}
	return (check);
}

/**
 * _strlen -  gets length of string
 * @s: pointer
 *
 * Return: Return pointer char (so movements are 1 byte)
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * zerox -  moves to the left and adds a zero
 * @s: pointer
 * @n: number of zeros wanted
 * @size: size
 *
 * Return: Return pointer
 */
char *zerox(char *s, int n, int size)
{
	int i, j;

	if (n == 0)
		return (s);

	for (j = 0; j < n; j++)
	{
		for (i = 0; i < size - 2; i++)
		{
			s[i] = s[i + 1];
		}
		for (i = size - 2; i < size - 1; i++)
			s[i] = '0';
		s[i] = '\0';
	}
	return (s);
}
/**
 * infinite_add -  adds 2 numbers
 * @n1: number 1
 * @n2: number 2
 * @r: buffer
 *
 * Return: Return pointer
 */
char *infinite_add(char *n1, char *n2, char *r)
{
	int i = 0, j = 0, diff, big, small, cyc, cyc2, count, tmp, ten, size_r;
	char *less, *more;

	i = _strlen(n1);
	j = _strlen(n2);

	if (i >= j)
		big = i, small = j, diff = i - j + 1, less = n2, more = n1;
	else
		big = j, small = i, diff = j - i + 1, less = n1, more = n2;
	count = 0, cyc = diff, ten = 0, size_r = big + 2;

	for (count = 0; count < small; count++, cyc++)
		r[cyc] = less[count];
	for (cyc2 = big; cyc2 >= 1; cyc2--)
	{
		if (cyc > size_r)
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
	r[big] = '\0';

	return (r);
}
/**
 * main - Entry point
 *
 * @argc: Counts the number of parameters that go into main
 * @argv: Pointer of array of pointers containing strings entering main
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int i, j, k, l1 = 0, l2 = 0, small, big, tmp, ten, zeros = 0, sizemall;
	char *less, *more, *mless, *adds1, *addsall, *r;

	if (argc != 3 || _isnumber(argv[1]) == 0 || _isnumber(argv[2]) == 0)
	{
		printf("Error\n");
		exit(98);
	}
	l1 = _strlen(argv[1]), l2 = _strlen(argv[2]);
	if (l1 >= l2)
		big = l1, small = l2, more = argv[1], less = argv[2];
	else
		big = l2, small = l1, more = argv[2], less = argv[1];
	sizemall = big + small, r = _callocX(big + 1), mless = _callocX(small);
	adds1 = _callocX(sizemall), addsall = infinite_add("0", adds1, r);
	if (mless == 0 || adds1 == 0 || r == 0)
		return (0);
	free(adds1);
	for (i = big - 1, j = small - 1; j >= 0; i--, j--)
		mless[i] = less[j];
	for (i = big - 1; i >= 0; i--)
	{
		adds1 = _callocX(big + small);
		if (mless[i] != '0')
		{
			ten = 0;
			for (j = big - 1, k = (sizemall - 1); j >= 0; j--, k--)
			{
				tmp = (mless[i] - '0') * (more[j] - '0') + ten;
				ten = tmp / 10, tmp = tmp - (ten * 10);
				adds1[k] = '0' + tmp;
			}
			adds1[k] = '0' + ten;
		}
		adds1 = zerox(adds1, zeros, sizemall + 1);
		addsall = infinite_add(adds1, addsall, r), zeros++;
		free(adds1);
	}
	free(mless), printf("%s\n", addsall);
	return (0);
}

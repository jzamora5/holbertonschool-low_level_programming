#include "holberton.h"

/**
 * _pow - obtains result of a base with exponent power unsigned int
 * @base: number that is base
 * @power: exponent
 *
 * Return: Result of operation
 */
unsigned int _pow(unsigned int base, unsigned int power)
{
	unsigned int i, res = base;

	if (power == 0)
		return (1);
	for (i = 1; i < power; i++)
		res *= base;

	return (res);
}
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: b is pointing to a string of 0 and 1 chars
 *
 * Return: Converted number or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0, i;
	int l = 0;

	if (b == 0)
		return (0);


	while (b[l] != 0)
	{
		if (b[l] != '0' && b[l] != '1')
			return (0);
		l++;
	}

	l = l - 1;

	for (i = 0; l >= 0; i++, l--)
		res += (b[l] - '0') * _pow(2, i);

	return (res);

}

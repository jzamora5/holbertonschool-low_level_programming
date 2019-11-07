#include "holberton.h"

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another
 * @n: base 10 number
 * @m: base 10 number
 *
 * Return: Number of bits you would need to flip
 *
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int r;
	int count = 0;

	r = n ^ m;

	while (r != 0)
	{
		count += r & 1;
		r = r >> 1;
	}

	return (count);
}

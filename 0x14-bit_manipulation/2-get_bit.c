#include "holberton.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: base 10 number
 * @index: index to print
 *
 * Return: value of the bit at index index or -1 if an error occured
 *
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0, bit;

	if (index > 63)
		return (-1);

	for (i = 0; i < index; i++)
		n = n >> 1;

	if ((n & 1) == 1)
		bit = 1;

	if ((n & 1) == 0)
		bit = 0;

	return (bit);
}

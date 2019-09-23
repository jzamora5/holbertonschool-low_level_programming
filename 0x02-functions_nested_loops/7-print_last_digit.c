#include "holberton.h"

/**
 * print_last_digit - returns the value of the last digit of n
 * @n: An integer number
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_last_digit(int n)
{
	int i;

	i = n % 10;
	if (i < 0)
	{
		i = i * -1;
	}
	_putchar('0' + i);
	return (i);
}

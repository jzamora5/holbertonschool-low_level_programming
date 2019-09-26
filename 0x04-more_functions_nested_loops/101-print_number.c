#include "holberton.h"

/**
 * print_number - prints a number with _putchar
 * @n: Number to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_number(int n)
{
	int digit, ten, i, negative;

	if (n < 0)
	{
		n = n * -1;
		negative = 1;
	}
	digit = n;
	ten = 1;
	while (digit >= 10)
	{
		digit = digit / 10;
		ten = ten * 10;
	}
	if (negative == 1)
	{
		_putchar('-');
	}
	_putchar('0' + digit);
	i = ten / 10;
	while (i >= 1)
	{
		_putchar('0' + (n / i) % 10);
		i = i / 10;
	}
}

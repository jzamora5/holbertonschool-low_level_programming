#include "holberton.h"

/**
 * print_most_numbers - prints numbers from 0 to 9, but 2 and 4
 * void: No Input Parameter
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_most_numbers(void)
{
	int i;

	for (i = 48; i < 58; i++)
	{
		if ((i != 50) && (i != 52))
		{
			_putchar(i);
		}
	}
	_putchar('\n');
}

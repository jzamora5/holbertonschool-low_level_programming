#include "holberton.h"

/**
 * print_numbers - prints numbers from 0 to 9
 * void: No Input Parameter
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_numbers(void)
{
	int i;

	for (i = 48; i < 58; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}

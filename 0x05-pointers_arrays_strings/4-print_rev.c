#include "holberton.h"

/**
 * print_rev - prints a string in reverse
 * @str: string
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_rev(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		_putchar(str[i]);
		i--;
	}
	_putchar('\n');
}

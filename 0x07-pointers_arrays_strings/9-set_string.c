#include "holberton.h"
#include <stdio.h>

/**
 * set_string - sets the value of a pointer to a char
 *
 * @s: double pointer
 * @to: pointer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void set_string(char **s, char *to)
{
	*s = to;
}

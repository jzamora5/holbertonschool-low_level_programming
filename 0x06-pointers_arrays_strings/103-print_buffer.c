#include "holberton.h"
#include <stdio.h>
/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_buffer(char *b, int size)
{
	int i, j, k, f;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		for (j = i; j < i + 10; j += 2)
		{
			for (k = j; k <= j + 1; k++)
				if ((b[k] != 0) && (k < size))
					printf("%02x", b[k]);
				else if (k < size)
					printf("%02x", 0);
				else
					printf("  ");
			printf(" ");
		}
		for (f = i; f < i + 10; f++)
		{
			if ((b[f] >= 32 && b[f] <= 126) && (f < size))
				printf("%c", b[f]);
			else if (f < size)
				printf("%c", '.');
		}
		printf("\n");
	}
}

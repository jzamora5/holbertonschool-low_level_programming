#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array of type int
 * @size: size of array
 * @cmp: function with argument int and no return
 *
 * Return: No element matches -1, if size <=0 -1
 * else index of first element cmp func does not rtrn 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i, f = 0;

	if (cmp || size <= 0 || array)
		return (-1);

	for (i = 0; i < size && f == 0; i++)
		f = cmp(array[i]);

	if (i == size)
		i = 0;

	return (i - 1);
}

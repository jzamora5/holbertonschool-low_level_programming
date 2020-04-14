#include "search_algos.h"

/**
 * print_array - Prints an array between two boundaries
 * @array: pointer to the first element of the array to print
 * @min: left boundary
 * @max: right boundary
 *
 * Return: No Return
 */
void print_array(int *array, int min, int max)
{
	int i;

	for (i = min; i < max; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}

/**
 * binary_search - searches for a value in a sorted array of integers using the
 * Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size:  number of elements in array
 * @value: value to search for
 *
 * Return: Index where value is located or -1
 */
int binary_search(int *array, size_t size, int value)
{
	int min, max, mid;

	if (!array)
		return (-1);

	min = 0, max = size - 1;
	while (min <= max)
	{
		printf("Searching in array: ");
		print_array(array, min, max);
		mid = (min + max) / 2;
		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			min = mid + 1;
		else
			max = mid - 1;
	}

	return (-1);
}

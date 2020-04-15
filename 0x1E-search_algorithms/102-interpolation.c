#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size:  number of elements in array
 * @value: value to search for
 *
 * Return: Index where value is located or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, high, low;

	if (!array || size == 0)
		return (-1);

	low = 0, high = size - 1;

	while (low < high)
	{
		pos = low + (((double)(high - low) /
			      (array[high] - array[low])) * (value - array[low]));

		if (pos > (size - 1))
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}
		else
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (pos == 0 && array[pos] > value)
			return (-1);

		if (array[pos] > value)
			high = pos - 1;
		else if (array[pos] < value)
			low = pos + 1;
		else
			return (pos);
	}

	if (array[low] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);
		return (low);
	}

	return (-1);
}

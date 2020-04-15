#include "search_algos.h"

/**
 * print_arrayAd - Prints an array between two boundaries
 * @array: pointer to the first element of the array to print
 * @min: left boundary
 * @max: right boundary
 *
 * Return: No Return
 */
void print_arrayAd(int *array, int min, int max)
{
	int i;

	for (i = min; i < max; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}
/**
 * auxBinary - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @min: left boundary
 * @max: right bounday
 * @value: value to search for
 *
 * Return: Index where value is located or -1
 */
int auxBinary(int *array, int min, int max, int value)
{
	int mid;

	if (min > max)
		return (-1);

	printf("Searching in array: ");
	print_arrayAd(array, min, max);


	if (min == max && array[max] == value)
		return (max);

	if (min == max && array[max] != value)
		return (-1);

	mid = min + (max - min) / 2;

	if ((mid == min || value != array[mid - 1]) && array[mid] == value)
		return (mid);

	if (array[mid] >= value)
		return (auxBinary(array, min, mid, value));
	return (auxBinary(array, mid + 1, max, value));

}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the Binary search algorithm (Returns First Ocurrence)
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: First index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (!array || size == 0)
		return (-1);

	return (auxBinary(array, 0, size - 1, value));
}

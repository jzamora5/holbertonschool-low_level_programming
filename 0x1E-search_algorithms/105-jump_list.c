#include "search_algos.h"
#include <math.h>
/**
 * list_move - moves list x positions
 * using the Jump search algorithm.
 * @list: pointer to the node of list
 * @x: positions to move
 *
 * Return: Pointer to new node or NULL
 */
listint_t *list_move(listint_t *list, int x)
{
	int i;

	for (i = 0; list->next && i < x; i++)
		list = list->next;

	return (list);
}
/**
 * jump_list - searches for a value in a sorted list of integers
 * using the Jump search algorithm.
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: Pointer to first node where value is located or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, pos, i, min;
	listint_t *node_pos, *node_min;

	if (!list || size == 0)
		return (NULL);

	pos = 0, min = 0;
	node_pos = list, node_min = list;
	step = sqrt(size);

	while (node_pos && (node_pos->n) < value)
	{
		min = pos;
		node_min = node_pos;
		pos += step;

		if (pos > (size - 1))
			pos = size - 1;

		node_pos = list_move(node_pos, step);
		printf("Value checked array[%zu] = [%d]\n", pos, node_pos->n);


		if (pos == (size - 1))
			break;
	}

	printf("Value found between indexes [%zu] and [%zu]\n", min, pos);

	for (i = min; i <= pos && i < size; i++, node_min = node_min->next)
	{
		printf("Value checked array[%zu] = [%d]\n", i, node_min->n);
		if (node_min && (node_min->n) == value)
			return (node_min);
	}

	return (NULL);
}

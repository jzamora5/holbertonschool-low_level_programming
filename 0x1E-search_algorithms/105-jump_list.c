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
	size_t step, i;
	listint_t *node_pos, *node_min;

	if (!list || size == 0)
		return (NULL);

	node_pos = list, node_min = list;
	step = sqrt(size);

	while (node_pos && node_pos->next && (node_pos->n) < value)
	{
		node_min = node_pos;

		node_pos = list_move(node_pos, step);
		printf("Value checked at index [%lu] = [%d]\n",
		       node_pos->index, node_pos->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       node_min->index, node_pos->index);

	for (i = node_min->index;
	     i <= (node_pos->index) && i < size && (node_min->n <= value);
	     i++, node_min = node_min->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, node_min->n);
		if (node_min && (node_min->n) == value)
			return (node_min);
	}

	if (node_min)
		printf("Value checked at index [%lu] = [%d]\n", i, node_min->n);

	return (NULL);
}

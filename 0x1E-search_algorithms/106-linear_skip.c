#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: Pointer on the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i;
	skiplist_t *node_pos, *node_min;

	if (!list)
		return (NULL);

	node_pos = list, node_min = list;

	while (node_pos && node_pos->next && (node_pos->n) < value)
	{
		node_min = node_pos;

		if (node_pos->express)
		{
			node_pos = node_pos->express;

			printf("Value checked at index [%lu] = [%d]\n",
			       node_pos->index, node_pos->n);
		}
		else
			while (node_pos->next)
				node_pos = node_pos->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       node_min->index, node_pos->index);

	for (i = node_min->index;
	     i <= (node_pos->index) && (node_min->n <= value);
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

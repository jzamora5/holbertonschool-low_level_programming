#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list (can free lists with a loop)
 * @h: pointer to head of singly linked list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp = *h, *tmp2;
	unsigned int count = 0;

	if (tmp == 0 || h == 0)
		return (0);

	tmp = *h;
	while (tmp != 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		count++;

		free(tmp2);

		if (tmp2 <= tmp)
			break;
	}

	*h = 0;
	return (count);
}

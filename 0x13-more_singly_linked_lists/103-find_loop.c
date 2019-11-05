#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - inds the loop in a linked list
 * @head: pointer to head of singly linked list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp, *tmp2;

	tmp = head;

	if (tmp == 0)
		return (0);

	if (head == head->next)
		return (head);

	while (tmp != 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;

		if (tmp2 <= tmp)
			return (tmp);
	}

	return (0);
}

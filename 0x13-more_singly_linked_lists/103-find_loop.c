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
	listint_t *tmp;

	if (head == 0)
		exit(98);

	while (head != 0)
	{
		tmp = head;
		head = head->next;

		if (tmp < head)
			return (head);
	}

	return (0);
}

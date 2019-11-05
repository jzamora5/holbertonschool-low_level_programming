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

	if (tmp == tmp->next)
		return (tmp);

	while (tmp != 0)
	{
		tmp2 = head;
		tmp = tmp->next;


		while (tmp2 != tmp && tmp != 0)
		{

			if (tmp->next == tmp)
				return (tmp);
			if (tmp->next == tmp2)
				return (tmp2);

			tmp2 = tmp2->next;
		}
	}
	return (tmp);
}

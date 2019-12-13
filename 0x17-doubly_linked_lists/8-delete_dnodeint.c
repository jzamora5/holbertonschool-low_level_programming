#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: pointer to head of doubly linked list
 * @index: index to look for
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmpcount = *head, *tmp1 = *head, *tmp2, *tmp3;
	unsigned int count = 0;

	if (!head || !(*head))
		return (-1);
	while (tmpcount)
		tmpcount = tmpcount->next, count++;
	if (index > (count - 1))
		return (-1);

	if (index == 0)
	{
		tmp1 = tmp1->next;
		free(*head);
		*head = tmp1;
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}

	for (count = 0; count < index; count++)
		tmp2 = tmp1, tmp1 = tmp1->next;

	tmp2->next = tmp1->next;
	tmp3 = tmp1->next;
	if (tmp3)
		tmp3->prev = tmp2;
	free(tmp1);
	return (1);
}

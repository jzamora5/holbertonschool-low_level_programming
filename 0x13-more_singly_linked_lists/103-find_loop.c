#include "lists.h"
#include <stdio.h>
/**
 * find_listint_loop - finds address of starting node in looped linked list
 * @head: pointer to the head in linked list to test
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *tortoise;

	if (!head)
		return (NULL);

	hare = tortoise = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = (hare->next)->next;

		if (hare == tortoise)
		{
			tortoise = head;

			while (tortoise && hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;

				if (tortoise == hare)
					return (tortoise);
			}
		}
	}

	return (NULL);
}

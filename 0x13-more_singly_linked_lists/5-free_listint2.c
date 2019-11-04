#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees memory of a list
 * @head: pointer to head of singly linked list
 *
 * Return: No Return
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp = *head;
	listint_t *tmp2;

	if (tmp == 0)
		return;

	while (tmp != 0)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}

	*head = 0;

}

#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees memory of a list
 * @head: head pointer of singly linked list
 *
 * Return: No Return
 */
void free_listint(listint_t *head)
{
	if (head == 0)
		return;

	free_listint(head->next);
	free(head);
}

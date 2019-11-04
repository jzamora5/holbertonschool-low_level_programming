#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to head of singly linked list
 *
 * Return: head node’s data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp = *head;
	listint_t *tmp2 = tmp->next;
	int n;

	if (tmp == 0)
		return (0);

	n = tmp->n;
	free(tmp);
	*head = tmp2;

	return (n);
}

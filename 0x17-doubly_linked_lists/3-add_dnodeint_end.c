#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to head of doubly linked list
 * @n: numeric value wanted in new node
 *
 * Return: address to the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *tmp = *head;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	if (!(*head))
	{
		new_node->prev = NULL, new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next)
		tmp = tmp->next;

	new_node->prev = tmp;
	new_node->next = NULL;
	tmp->next = new_node;
	return (new_node);
}

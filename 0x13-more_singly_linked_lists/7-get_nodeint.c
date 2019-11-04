#include "lists.h"

/**
 * get_nodeint_at_index -  returns the nth node of a listint_t linked list
 * @head: head pointer of singly linked list
 * @index: index to find in list
 *
 * Return: nth node of a listint_t linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head == 0)
		return (0);

	while (count < index)
	{
		if (head == 0)
			return (0);
		head = head->next;
		count++;
	}
	return (head);
}

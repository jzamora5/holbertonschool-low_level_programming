#include "lists.h"
#include <stddef.h>

/**
 * listint_len -  returns the number of elements in a linked listint_t list
 * @h: pointer to head of singly linked list
 *
 * Return: Number of elements in list
 */
size_t listint_len(const listint_t *h)
{
	unsigned int size = 0;

	while (h != 0)
		h = h->next, size++;

	return (size);
}

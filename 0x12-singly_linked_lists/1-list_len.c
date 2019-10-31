#include "lists.h"
#include <stddef.h>

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to head of singly linked list
 *
 * Return: Number of elements in list
 */

size_t list_len(const list_t *h)
{
	unsigned int size = 0;

	while (h != NULL)
		h = h->next, size++;

	return (size);
}

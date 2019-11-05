#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - prints a singly linked list (can print lists with loop)
 * @head: head pointer of singly linked list
 *
 * Return: Number of elements in list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp, *tmp2;
	unsigned int count = 0;

	tmp = head;
	if (tmp == 0)
		return (0);

	while (tmp != 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;

		count++;

		printf("[%p] %d\n", (void *)tmp2, tmp2->n);

		if (tmp2 <= tmp)
		{
			printf("-> [%p] %d\n", (void *)tmp, tmp->n);
			break;
		}
	}

	return (count);
}

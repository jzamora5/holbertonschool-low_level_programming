#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - prints a singly linked list (can print lists with loop)
 * @head: pointer to head of singly linked list
 *
 * Return: Number of elements in list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp;
	unsigned int count = 0;

	if (head == 0)
		exit(98);

	while (head != 0)
	{
		tmp = head;
		head = head->next;
		count++;

		printf("[%p] %d\n", (void *)tmp, tmp->n);

		if (tmp < head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
	}

	return (count);
}

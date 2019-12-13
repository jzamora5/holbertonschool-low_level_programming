#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data (n) of a dlistint_t linked list
 * @head: pointer to head of doubly linked list
 *
 * Return: sum of data or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	unsigned int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

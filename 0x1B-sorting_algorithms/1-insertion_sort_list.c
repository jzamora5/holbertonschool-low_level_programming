#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: No Return
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;

	if (!(*node)->prev)
		*list = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;

}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: No Return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *head = *list, *tback, *aux;

	if (!head || (!(head->prev) && !(head->next)))
		return;

	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			aux = head;

			_swap(&aux, list);
			print_list(*list);
			head = aux;
			tback = aux;

			while (tback && tback->prev)
			{

				if (tback->n < tback->prev->n)
				{
					aux = tback->prev;

					_swap(&(aux), list);

					print_list(*list);
					tback = aux->next;
				}

				tback = tback->prev;
			}

		}
		head = head->next;
	}
}

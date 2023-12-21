#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */

void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *temp1, *temp2;

	temp1 = n1->prev;
	temp2 = n2->next;

	n1->prev = n2;
	n1->next = temp2;

	n2->prev = temp1;
	n2->next = n1;

	if (temp1 != NULL)
	{
		temp1->next = n2;
	}
	else
	{
		*list = n2;
	}

	if (temp2 != NULL)
	{
		temp2->prev = n1;
	}
}

/**
 * insertion_sort_list - Sorts list in ascending order using insertion sort.
 * @list: A double pointer to the list to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;
	int temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (i = (*list)->next; i != NULL; i = i->next)
	{
		j = i->prev;
		temp = i->n;
		while (j != NULL && j->n > temp)
		{
			swap_nodes(list, j, i);
			print_list(*list);
			j = i->prev;
		}
	}
}

#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */

void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
	a->prev->next = b;
	if (b->next)
	b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *                       using the Insertion Sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current->prev;
		temp = current;

	while (insert && insert->n > temp->n)
	{
		swap_nodes(insert, temp);
		if (!temp->prev)

		*list = temp;
		print_list(*list);
		insert = temp->prev;
	}
		current = current->next;
	}
}

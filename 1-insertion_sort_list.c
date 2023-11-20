#include "sort.h"

/**
 * swap_nodes - Swap two node on a Dlist.
 * @list: head of the Dlist
 * @current: Current node
 * @previous: previous node
 */
void swap_nodes(listint_t **list, listint_t *current, listint_t *previous)
{
	if (current->next)
	{
		(current->next)->prev = previous;
		previous->next = current->next;
	}

	current->prev = previous->prev;
	current->next = previous;

	if (previous->prev)
	{
		(previous->prev)->next = current;
		previous->prev = current;
	}
	else
		(*list) = current;
}

/**
 * insertion_sort_list - sort a DLlist using insertion sort algo
 * @list: Doubly linked list of integers(Dlist)
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous = NULL, *current = NULL, *next = NULL;

	if (!list || !(*list))
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		previous = current->prev;

		while (previous && current->n < previous->n)
		{
			previous->next = current->next;

			swap_nodes(list, current, previous);
			previous->prev = current;
			previous = current->prev;

			print_list(*list);
		}
		current = next;
	}
}

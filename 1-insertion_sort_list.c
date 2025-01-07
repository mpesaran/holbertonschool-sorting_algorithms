#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: a linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *next, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (current)
	{
		next = current->next;
		tmp = current->prev;
		while (tmp && current->n < tmp->n)
		{
			if (tmp->prev)
				tmp->prev->next = current;
			if (current->next)
				current->next->prev = tmp;
			current->prev = tmp->prev;
			tmp->next = current->next;
			current->next = tmp;
			tmp->prev = current;
			if (!current->prev)
				*list = current;
			tmp = current->prev;
			print_list(*list);
		}
		current = next;
	}
}

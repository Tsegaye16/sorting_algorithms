#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 *	of integers in ascending order
 *	using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: The function sorts the doubly linked list using
 *	the Insertion sort  algorithm and swaps the nodes
 *	themselves (not the integer values).
 *   It prints the list after each swap of two elements.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *temp;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
	}
}

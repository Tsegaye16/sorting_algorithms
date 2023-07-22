#include <stdio.h>
#include "sort.h"
/**
 * print_list - The function that prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int n = 0;

	while (list)
	{
		if (n > 0)
			printf(", ");
		printf("%d", list->next);
		++n;
		list = list->next;
	}
	printf("\n");
}

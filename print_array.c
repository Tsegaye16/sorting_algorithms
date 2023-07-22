#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - The merhod that prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t n = 0;

	while (array && n < size)
	{
		if (n > 0)
			printf(", ");
		printf("%d", array[n]);
		++n;
	}
	printf("\n");
}

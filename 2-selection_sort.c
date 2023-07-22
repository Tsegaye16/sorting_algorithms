#include "sort.h"

/**
 * swap - The function that swaps two integers in an the array
 * @a: first number
 * @b: second number
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - The function that implements the selection sort logic.
 * @array: the array to be sorted
 * @size:size of the array
 */
void selection_sort(int *array, size_t size)
{
	/**
	 * look for the smallest element
	 * swap the smallest element with the current
	 */
	unsigned int i = 0, j = 0, tmp_loc = 0;
	int tmp;

	while (i < size)
	{
		j = i;
		tmp = array[j], tmp_loc = j;
		while (j < size)
		{
			if (array[j] < tmp)
				tmp = array[j], tmp_loc = j;
			j++;
		}
		if (array[i] != array[tmp_loc])
		{
			swap(array + i, array + tmp_loc);
			print_array(array, size);
		}
		i++;
	}
}

#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *	using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * Description: The function sorts the array using the Shell sort algorithm
 *	with the Knuth sequence and prints the array each time it
 *	decreases the interval.
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	size_t interval = 1;

	while (interval < size / 3)
		interval = interval * 3 + 1;
	while (interval >= 1)
	{
		size_t i, j;
		int temp;

		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}

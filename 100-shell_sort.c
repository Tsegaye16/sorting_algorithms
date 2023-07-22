#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *	using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: The function sorts the array using the Shell sort algorithm
 *	with the Knuth sequence and prints the array each time it
 *	decreases the interval.
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	size_t interval = 1;

	/**
	 * Calculate the initial interval using the Knuth sequence
	 */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		size_t i, j;
		int temp;

		/**
		 * Shell insertion sort with the current interval
		 */
		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		print_array(array, size);

		/**
		 * Decrease the interval using the Knuth sequence
		 */
		interval = (interval - 1) / 3;
	}
}

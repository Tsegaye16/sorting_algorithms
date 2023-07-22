#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: First number.
 * @b: Second number.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme for Quick sort.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: Size of the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive - Recursive function for Quick sort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = hoare_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *	using the Quick sort algorithm with Hoare partition.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: The function sorts the array using the Quick sort algorithm
 *	with Hoare partition scheme and prints the array after each
 *	time you swap two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

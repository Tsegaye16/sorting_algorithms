#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The original array containing the two subarrays.
 * @left: The starting index of the left subarray.
 * @mid: The ending index of the left subarray (mid + 1
 *	is the starting index of the right subarray).
 * @right: The ending index of the right subarray.
 * @tmp: Temporary array to store the merged subarrays.
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *tmp)
{
	size_t i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
	{
		if (array[i] < array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i <= mid)
		tmp[k++] = array[i++];
	while (j <= right)
		tmp[k++] = array[j++];
	for (i = left, k = 0; i <= right; i++, k++)
		array[i] = tmp[k];
}

/**
 * merge_sort_recursive - Recursive function for Merge sort.
 * @array: The array to be sorted.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 * @tmp: Temporary array to store merged subarrays.
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *tmp)
{
	if (left < right)
	{
		size_t mid = (left + right) / 2;

		merge_sort_recursive(array, left, mid, tmp);
		merge_sort_recursive(array, mid + 1, right, tmp);
		merge(array, left, mid, right, tmp);
		print_array(array + left, right - left + 1);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *	using the Merge sort algorithm (top-down approach).
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: The function sorts the array using the top-down Merge sort
 *	algorithm and prints the array after each merge operation.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	int *tmp = malloc(sizeof(int) * size);

	if (tmp == NULL)
		return;
	merge_sort_recursive(array, 0, size - 1, tmp);
	free(tmp);
}

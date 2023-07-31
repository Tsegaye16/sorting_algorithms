#include "sort.h"
/**
 * swap - Swaps two int values
 * @array: the integer array to sort
 * @left: address of first value
 * @right: address of second value
 * @size: the size of the array
 *
 * Return: Void
 */
void swap(int *array, int *left, int *right, size_t size)
{
	int temp;

	if (left != right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		print_array(array, size);
	}
}
/**
 * hoare - Evaluates new array
 * @array: Array
 * @left: Start point
 * @right: End point
 * @size: Pointer to the previous element of the list
 *
 * Description: New partitions
 * Return: int Pivot
 */
int hoare(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1, j = right + 1;

	while (i < (int) size)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i >= j)
			break;
		swap(array, &array[i], &array[j], size);
	}
	return (i);
}
/**
 * Qsort - Recursion to quick sort
 * @array: Array
 * @left: Start point
 * @right: End point
 * @size: Pointer to the previous element of the list
 *
 * Description: New partitions
 * Return: int Pivot
 */
void Qsort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = hoare(array, left, right, size);
		Qsort(array, left, pivot - 1, size);
		Qsort(array, pivot, right, size);
	}
}
/**
 * quick_sort_hoare - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in ascending
 * order using the Quick sort hoare algorithm
 * Return: Void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	Qsort(array, 0, size - 1, size);
}

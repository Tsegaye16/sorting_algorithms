#include "sort.h"
/**
 * shell_sort -The function that sort an array
 *	using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, m, n;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (m = gap; m < size; m++)
		{
			temp = array[m];
			n = m;
			while (n >= gap && array[n - gap] > temp)
			{
				array[n] = array[n - gap];
				n -= gap;
			}
			array[n] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}

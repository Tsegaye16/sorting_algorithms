#include "sort.h"
/**
 * counting_sort - the mthod that sorts an array
 *	with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max, num, y, l;
	size_t x, k, m, n;

	if (size < 2)
		return;

	max = array[0];
	for (x = 1; x < size; x++)
		if (array[x] > max)
			max = array[x];

	count_arr = malloc(sizeof(size_t) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	for (y = 0; y <= max; y++)
		count_arr[y] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_arr[num] += 1;
	}
	for (l = 1; l <= max; l++)
		count_arr[l] += count_arr[l - 1];
	print_array(count_arr, max + 1);
	for (m = 0; m < size; m++)
	{
		out_arr[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(count_arr);
	free(out_arr);
}

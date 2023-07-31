#include "sort.h"
/**
* swapint - the method that swaps index's of array
* @l: left or low index to swap
* @r: right or high index
*/

void swapint(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
* b_merge - logic of bitonic merge
* @array: Array slice being merged
* @low: lowest index
* @count: Count of slice
* @dir: Direction, ascending 1 descending 0
* @size: size of total array for printing
*/

void b_merge(int *array, int low, int count, int dir, size_t size)
{
	int m, n;

	if (count > 1)
	{
		n = count / 2;
		for (m = low; m < low + n; m++)
		{
			if (((array[m] > array[m + n]) && dir == 1) ||
			(dir == 0 && (array[m] < array[m + n])))
				swapint(&array[m], &array[m + n]);
		}
		b_merge(array, low, n, dir, size);
		b_merge(array, low + n, n, dir, size);
	}
}

/**
* b_sort - the method of bitonic sort recursively
* @array: array to sort
* @low: lowest index
* @count: Count of slice
* @dir: Direction, ascending 1 descending 0
* @size: size of total array for printing
*/

void b_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		b_sort(array, low, n, 1, size);
		b_sort(array, low + n, n, 0, size);
		b_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort -the method that sorts array using bitonic logic
* @array: Array to sort
* @size: Size of array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	b_sort(array, 0, size, 1, size);
}

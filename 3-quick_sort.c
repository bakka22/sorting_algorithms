#include "sort.h"
/*
*
*
*
*
*/
void sort(int *array, int low, int high, size_t size)
{
	int i, j, pivot, tmp;

	if (low == high)
		return;

	j = low;
	i = low - 1;
	pivot = array[high];
	for (; j <= high; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 < high)
		sort(array, i + 1, high, size);
	if (i - 1 > low)
		sort(array, low, i - 1, size);
}

/**
*
*
*
*
*/

void quick_sort(int *array, size_t size)
{

	if (size <= 1 || !array)
		return;
 	sort(array, 0, (int)(size - 1), size);
}
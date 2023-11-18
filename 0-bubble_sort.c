#include "sort.h"

/**
* bubble_sort - sort an array using bubble sort algorithm
*@array: array to be sorted
*@size: size of the array
*Return: nothing
*/

void bubble_sort(int *array, size_t size)
{
	int i, swap = 0, j, lim, tmp;

	if (size <= 1 || !array)
		return;

	lim = (int)size;
	for (i = 0; i < (int)size - 1; i++)
	{
		swap = 0;
		lim--;
		for (j = 0; j < lim; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			return;
	}
}

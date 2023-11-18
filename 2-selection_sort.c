#include "sort.h"

/**
*selection_sort - sort an array using selection sort algorithm
*@array: array to be sorted
*@size: size of the array
*Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	int min = 0, i, j, idx2 = 0, tmp = 0, swap = 0;

	if (!array || size <= 1)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		swap = 0;
		min = array[i];
		for (j = i; j < (int)size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx2 = j;
				swap = 1;
			}
		}
		if (swap)
		{
			tmp = array[i];
			array[i] = array[idx2];
			array[idx2] = tmp;
			print_array(array, size);
		}
	}
}

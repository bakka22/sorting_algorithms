#include "sort.h"
#include <stdio.h>
/**
*swap2 - swap two elements in an array
*@array: array used
*@idx1: index of the first element
*@idx2: index of the second element
*Return: nothing
*/
void swap2(int *array, int idx1, int idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}
/**
*shell_sort - sort an array using shell sort
*@array: array to be sorted
*@size: size of the array
*Return: nothing
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < (int)size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap)
	{
		for (i = gap; i < (int)size; i++)
		{
			j = i;
			while (j - gap > 0 && array[j] < array[j - gap])
			{
				swap2(array, j, j - gap);
				j -= gap;
			}
		}
		gap = gap / 3;
		print_array(array, size);
	}
}

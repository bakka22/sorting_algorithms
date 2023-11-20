#include "sort.h"
/**
*sort - impelement quick sort recursivly
*@array: array to be sorted
*@low: the index to start in
*@high: the index to end in
*@size: size of the array
*Return: nothing
*/
void sort(int *array, int low, int high, size_t size)
{
	int i, j, pivot, tmp;

	if (low >= high || low < 0)
		return;

	j = low;
	i = low;
	pivot = array[high];
	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			print_array(array, size);
		}
	}	
	tmp = array[high];
	array[high] = array[i];
	array[i] = tmp;
	print_array(array, size);
	sort(array, i + 1, high, size);
	sort(array, low, i - 1, size);
}

/**
*quick_sort - sort an array using quick sort
*@array: array to be sorted
*@size: size of the array
*Return: nothing
*/

void quick_sort(int *array, size_t size)
{

	if (size <= 1 || !array)
		return;
	sort(array, 0, (int)(size - 1), size);
}

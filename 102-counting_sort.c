#include "sort.h"
#include <stdlib.h>

/**
*counting_sort - sort array using count sort algorithm
*@array: array to be sorted
*@size: size of the array
*Return: nothing
*/
void counting_sort(int *array, size_t size)
{
	int *count, i, tmp, max = 0;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (1 + max));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		tmp = array[count[array[i]] - 1];
		array[count[array[i]] - 1] = array[i];
		array[i] = tmp;
		count[tmp] -= 1;
	}
}

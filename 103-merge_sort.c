#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
void sor(int *array, int *arr2, size_t size, int low, int high, int choose)
{
	int x = 0, *src, *dist, i, j, k;

	if (choose % 2 == 0)
	{
		src = array;
		dist = arr2;
	}
	else
	{
		src = arr2;
		dist = array;
	}

	if(high - low < 1)
	{
		/*printf("cell : %d\n", src[low]);*/
		(void)dist;
		return;
	}

	x = (high - low + 1) / 2;
	sor(array, arr2, size, low, low + x - 1, choose + 1);
	sor(array, arr2, size, low + x, high, choose + 1);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = low; i < low + x; i++)
	{
		if (i != low)
			printf(", ");
		printf("%d", src[i]);
	}
	printf("\n");
	printf("[right]: ");
	for (i = low + x; i <= high; i++)
	{
		if (i != low + x)
			printf(", ");
		printf("%d", src[i]);
	}
	printf("\n");
	i = low;
	j = low + x;
	k = low;
	while(i < low + x && j <= high)
	{
		if (src[i] > src[j])
		{
			dist[k] = src[j];
			j++;
		}
		else
		{
			dist[k] = src[i];
			i++;
		}
		k++;
	}
	for (; i < low + x; i++)
	{
		dist[k] = src[i];
		k++;
	}
	for (; j <= high; j++)
	{
		dist[k] = src[j];
		k++;
	}
	printf("[Done]: ");
	for (k = low; k <= high; k++)
	{
		if (k != low)
			printf(", ");
		printf("%d", dist[k]);
	}
	printf("\n");
}
/**
*
*
*
*
*/

void merge_sort(int *array, size_t size)
{

	int *arr2, i;

	if (!array || size < 2)
		return;

	arr2 = malloc(sizeof(int) * size);
	if (arr2 == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		arr2[i] = array[i];

	sor(array, arr2, size, 0, size - 1, 0);	
	free(arr2);
}
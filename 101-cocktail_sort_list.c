#include "sort.h"
/**
*swap3 - swap two nodes
*@node1: the first node
*@node2: the seconde node
*Return: nothing
*/
void swap3(listint_t *node1, listint_t *node2)
{
	if (node2->prev)
		node2->prev->next = node1;
	if (node1->next)
		node1->next->prev = node2;
	node2->next = node1->next;
	node1->next = node2;
	node1->prev = node2->prev;
	node2->prev = node1;
}
/**
*cocktail_sort_list - sort a doubley linked list using insertion sort
*@list: pointer to the head of the list
*Return: nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp1;
	int swap = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	tmp1 = *list;
	while (swap)
	{
		swap = 0;
		while (tmp1->next)
		{
			if (tmp1->n > tmp1->next->n)
			{
				swap3(tmp1->next, tmp1);
				if (tmp1->prev->prev == NULL)
					(*list) = tmp1->prev;
				print_list(*list);
				swap = 1;
			}
			else
				tmp1 = tmp1->next;
		}
		if (!swap)
			break;
		swap = 0;
		while (tmp1->prev)
		{
			if (tmp1->n < tmp1->prev->n)
			{
				swap3(tmp1, tmp1->prev);
				if (tmp1->prev == NULL)
					(*list) = tmp1;
				print_list(*list);
				swap = 1;
			}
			else
				tmp1 = tmp1->prev;
		}
	}
}

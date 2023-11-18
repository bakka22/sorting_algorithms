#include "sort.h"
/**
*swap - swap two nodes
*@node1: the first node
*@node2: the seconde node
*Return: nothing
*/
void swap(listint_t *node1, listint_t *node2)
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
*insertion_sort_list - sort a doubley linked list using insertion sort
*@list: pointer to the head of the list
*Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	tmp1 = tmp2 = (*list)->next;
	while (tmp1 && tmp2)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		while (tmp2->prev != NULL && tmp2->n < tmp2->prev->n)
		{
			swap(tmp2, tmp2->prev);
			if (tmp2->prev == NULL)
				*list = tmp2;
			print_list(*list);
		}
	}
}

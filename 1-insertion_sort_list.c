#include "sort.h"

/**
* insertion_sort_list - Insertion method of sorting
*
* @list: doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *h, *node, *pre_node;

	if (!list || !(*list) || !(*list)->next)
		return;
	h = *list;

	while (h != NULL)
	{
		node = h;
		while ((node->prev != NULL) && (node->prev->n > node->n))
		{
			pre_node = node->prev;

			if (node->next != NULL)
			{
				node->next->prev = pre_node;
			}
			if (pre_node->prev != NULL)
			{
				pre_node->prev->next = node;
			}

			pre_node->next = node->next;
			node->next = pre_node;
			node->prev = pre_node->prev;
			pre_node->prev = node;

			if (node->prev == NULL)
			{
				*list = node;
			}

			print_list(*list);
		}

		h = h->next;
	}
}

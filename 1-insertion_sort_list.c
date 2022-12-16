#include "sort.h"
/**
 * insertion_sort_list - Doubly linked list node
 * @list: double linked list to sort
 * return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL)
		return;

	while (current != NULL)
	{
		temp = current;
		while (temp != NULL && temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap nodes */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			/* Print list after each swap */
			print_list(*list);
		}
		current = current->next;
	}
}

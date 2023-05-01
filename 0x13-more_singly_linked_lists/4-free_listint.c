#include "lists.h"

/**
 * free_listint - Deallocates memory used by the linked list.
 * @head: Linked list to be deallocated
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}


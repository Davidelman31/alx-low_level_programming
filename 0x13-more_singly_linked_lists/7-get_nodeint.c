#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node found at the given position
 * @head: Head node of the linked list
 * @index: Position of the node to return
 *
 * Return: target node pointer or None.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}

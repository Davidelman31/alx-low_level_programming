#include "lists.h"

/**
 * add_nodeint - Inserts a node at the front.
 * @head:  Anchor node pointer
 * @n:  Value for the new node
 *
 * Return: Pointer to the new node or None
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}


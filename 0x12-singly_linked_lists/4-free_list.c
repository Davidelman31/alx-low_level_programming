#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Writes a function that frees a list_t list.
 *
 * @head: Anchor
 */
void free_list(list_t *head)
{
	if (head)
	{
		free_list(head->next);
		if (head->str)
			free(head->str);
		free(head);
	}
}	

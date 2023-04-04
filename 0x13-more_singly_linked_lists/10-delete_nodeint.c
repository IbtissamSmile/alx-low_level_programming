#include "lists.h"

/**
 * delete_nodeint_at_index - the Function that delete a nodo
 * @head: nodo head
 * @index: index
 * Return: integer
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *copy = *head;
	unsigned int new_node;

	if (copy == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(copy);
		return (1);
	}

	for (new_node = 0; new_node < (index - 1); new_node++)
	{
		if (copy->next == NULL)
			return (-1);

		copy = copy->next;
	}

	current = copy->next;
	copy->next = current->next;
	free(current);
	return (1);
}

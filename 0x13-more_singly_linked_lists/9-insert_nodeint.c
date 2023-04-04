#include "lists.h"

/**
 * insert_nodeint_at_index - the Function insert node
 * @head: head nodo
 * @idx: index
 * @n: integer
 * Return: listint
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current = *head;
	unsigned int node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}

	for (node = 0; node < (idx - 1); node++)
	{
		if (current == NULL || current->next == NULL)
			return (NULL);

		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

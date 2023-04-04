#include "lists.h"

/**
 * get_nodeint_at_index - the Function return nth of the list
 * @head: the head nodos
 * @index: index of the nodo
 * Return: list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *new_node = head;
	unsigned int i;

	if (!head)
		return (0);
	for (i = 0; new_node; i++)
	{
		if (i == index)
			return (new_node);
		new = new_node->next;
	}
	return (NULL);
}

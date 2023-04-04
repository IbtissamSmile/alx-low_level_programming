#include "lists.h"
/**
 * add_nodeint - Function adds new nodo
 * @head: the pointer
 * @n: integer
 * Return: the list whit the new nodo
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

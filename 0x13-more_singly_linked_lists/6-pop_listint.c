#include "lists.h"

/**
 * pop_listint - the Function that deletes the head nodo
 * @head: head nodo
 * Return: the head node’s data
 */
int pop_listint(listint_t **head)
{
	listint_t *new_node = *head;
	int num;

	if (!*head)
		return (0);

	num = (*head)->n;
	*head = new_node->next;
	free(new_node);
	return (num);
}

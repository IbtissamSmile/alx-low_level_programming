#include "lists.h"

/**
 * reverse_listint - the Funtion Reverse the list
 * @head: head of linked list
 * Return: the first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *new_node = NULL, *next;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = start;
		start = *head;
		*head = next;
	}
	*head = new_node;
	return (*head);
}

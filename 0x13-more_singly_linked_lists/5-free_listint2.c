#include "lists.h"

/**
 * free_listint2 - the Funtions that free a list head = NULL
 * @head: the pointer
 *Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (!head)
		return;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
	*head = NULL;
}

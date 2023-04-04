#include "lists.h"

/**
 * free_listint - the Function free list
 * @head: the pointer
 * Return: nothing
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

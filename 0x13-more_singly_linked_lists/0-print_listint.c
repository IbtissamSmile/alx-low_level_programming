#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: the head of the list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes = 0;

	while (cursor != NULL)
	{
		printf("%d\n", cursor->n);
		nodes += 1;
		cursor = cursor->next;
	}
	return (nodes);
}

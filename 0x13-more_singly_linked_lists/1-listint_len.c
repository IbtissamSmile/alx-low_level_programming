#include "lists.h"

/**
 * listint_len - counts the number of nodes in a linked list
 * @h: the head of the list
 * Return: the number of elements
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *cursor = h;
	size_t nodes = 0;

	while (cursor != NULL)
	{
		nodes += 1;
		cursor = cursor->next;
	}
	return (nodes);
}

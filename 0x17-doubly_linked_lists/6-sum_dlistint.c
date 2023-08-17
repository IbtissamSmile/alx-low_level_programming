#include "lists.h"

/**
 * sum_dlistint - getting the sum of all nodes
 * @head: pointer to the first node
 * Return: the sum or 0 if empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);
	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

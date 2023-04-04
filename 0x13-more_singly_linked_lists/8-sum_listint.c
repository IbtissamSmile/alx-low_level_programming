#include "lists.h"

/**
 * sum_listint - the Function that sum lists
 * @head: head nodo
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum)
}

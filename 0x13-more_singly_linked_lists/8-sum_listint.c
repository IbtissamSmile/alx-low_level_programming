#include "lists.h"

/**
 * sum_listint - the Function that sum lists
 * @head: head nodo
 * Return: sum
 *         or 0 - if the list is empty
 */
int sum_listint(listint_t *head)
{
	int arr;

	arr = 0;

	while (head)
	{
		arr += head->n;
		head = head->next;
	}
	return (arr);
}

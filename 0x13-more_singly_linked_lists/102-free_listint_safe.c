#include "lists.h"

/**
 * free_listp2 - the frees a linked list
 * @head: A pointer to the head of a list.
 *
 * Return: the size of the list
 */
size_t free_listint_safe(listint_t **head)
{
	listint_t *temp_1 = *head, *temp_2;
	unsigned int iter = 0;

	if (temp_1 == 0 || head == 0)
		return (0);
	
	temp_1 = *head;
	while (temp_1 != 0)
	{
		temp_2 = temp_1;
		temp_1 = temp_1->next;
		iter++;

		free(temp_2);

		if (temp_2 <= temp_1)
			break;
	}

	*head = 0;
	return (iter);
}

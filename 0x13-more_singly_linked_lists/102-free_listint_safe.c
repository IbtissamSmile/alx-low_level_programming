#include "lists.h"

/**
 * free_listp2 - the frees a linked list
 * @head: A pointer to the head of a list.
 *
 * Return: no return.
 */
size_t looped_listint_count(listint_t *head)
{
	listp_t *temp;
	listp_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * free_listint_safe - The frees a linked list.
 * @h: A pointer to the head of a list.
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t new_nodes, index;

	new_nodes = looped_listint_count(*h);

	if (new_nodes == 0)
	{
		for (; h != NULL && *h != NULL; new_nodes++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}

	else
	{
		for (index = 0; index < new_nodes; index++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

		*h = NULL;
	}

	h = NULL;

	return (new_nodes);
}

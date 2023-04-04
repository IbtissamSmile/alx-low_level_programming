#include "lists.h"

/**
 * free_listp2 - the frees a linked list
 * @head: A pointer to the head of a list.
 *
 * Return: no return.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *cat, *dog;
	size_t new_nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	cat = head->next;
	dog = (head->next)->next;

	while (dog)
	{
		if (cat == dog)
		{
			cat = head;
			while (cat != dog)
			{
				new_nodes++;
				cat = cat->next;
				dog = dog->next;
			}

			cat = cat->next;
			while (cat != dog)
			{
				new_nodes++;
				cat = cat->next;
			}

			return (new_nodes);
		}

		cat = cat->next;
		dog = (dog->next)->next;
	}

	return (0);
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

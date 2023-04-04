#include "lists.h"

/**
 * find_listint_loop - the Funcion dada
 * @head: Desde main
 *
 * Return: the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *new_node1 = head, *new_node2 = head;

	while (new_node1 && new_node2 && new_node2->next)
	{
		new_node1 = new_node1->next;
		new_node2 = new_node2->next->next;
		if (new_node1 == new_node2)
		{
			new_node1 = head;
			while (new_node1 != new_node2)
			{
				new_node1 = new_node1->next;
				new_node2 = new_node2->next;
			}
			return (new_node1);
		}
	}
	return (NULL);
}

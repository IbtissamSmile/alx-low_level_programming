#include "search_algos.h"

/**
 * linear_search - searches of a values index
 * @array: Pointer to the first element
 * @size: Size of the array
 * @value: Element to be searched
 * Return: Index of the element or -1 if NULL or absent
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}

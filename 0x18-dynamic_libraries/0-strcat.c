#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2;

	len1 = 0;
	len2 = 0;

	while (dest[len1++])
	{
		len2++;
	}
	for (len1 = 0; src[len1]; len1++)
	{
		dest[len2++] = src[len1];
	}

	return (dest);
}

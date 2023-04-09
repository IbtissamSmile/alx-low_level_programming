#include "main.h"

/**
 * get_endianness - Checks the endianness.
 * Return: endian - 0. 
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian = (char *)&num;

	if (*endian == 1)
		return (1);

	return (0);
}

#include "main.h"
/**
 * flip_bits - Counts the number of bits needed to be
 * @n: The number.
 * @m: The number to flip
 * Return: The number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m, count = 0;

	while (diff > 0)
	{
		count += (diff & 1);
		diff >>= 1;
	}

	return (count);
}

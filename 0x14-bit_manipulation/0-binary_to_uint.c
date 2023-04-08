#include "main.h"

/**
 * binary_to_uint - the converts a binary number to an unsigned int
 * @b: binary number to be converted
 * Return: the unsigned int corresponding to binary number
 */
unsigned int binary_to_uint(const char *b)
{
	 unsigned int num = 0;
	  int len = strlen(b);

	  for (int i = 0; i < len; i++)
	  {
		  num = num << 1;
		  
		  if (b[i] == '1')
		  {
			  num = num | 1;
		  }
		  else if (b[i] != '0')
		  {
			   return 0;
		  }
	  }
	  return uint;
}

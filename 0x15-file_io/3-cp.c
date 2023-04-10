#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * error_file - the checks if files can be opened.
 * @file_from: file_from.
 * @file_to: the file_to.
 * Return: no return.
 */
int main(int ac, char **av)
{
	int o1, o2, nwr;
	int cl_1, cl_2, nrd;
	char buf_1[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}
	o1 = open(av[1], O_RDONLY);
	if (o1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	o2 = open(av[2], O_RDWR | O_CREAT | O_TRUNC, 00664);
	if (o1 == 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}

	nrd = read(o1, buf_1, 1024);
	nwr = write(o2, buf_1, nrd);

	if (nwr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}

	cl_1 = close(o1);
	if (cl_1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close o %d\n", o1);
		exit(100);
	}

	cl_2 = close(o2);
	if (cl_2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close o %d\n", o2);
		exit(100);
	}
	return (0);
}

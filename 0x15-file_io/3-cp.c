#include "main.h"

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 * Return: A pointer to the newly-allocated buffer.
 */
int main(int argc, char *argv[])
{
	int f_from, ft_o, nrd, cl_f, cl_t;
	char buff[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_from = open(argv[1], O_RDONLY);
	if (f_from  == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	ft_o = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while ((nrd = read(f_from, buff, BUFSIZ)) > 0)
		if (ft_o == -1 || (write(ft_o, buff, nrd) != nrd))
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	if (nrd == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	cl_f = close(f_from);
	cl_t = close(ft_o);
	if (cl_f == -1 || cl_t == -1)
	{
		if (cl_f == -1)
			dprintf(STDERR_FILENO,
					"Error: Can't close fd %d\n", f_from);
		else if (cl_t == -1)
			dprintf(STDERR_FILENO,
					"Error: Can't close fd %d\n", ft_o);
		exit(100);
	}
	return (0);
}

#include "main.h"

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 * Return: A pointer to the newly-allocated buffer.
 */
int main(int argc, char *argv[])
{
	int f_from, fto, rd, clf, clt;
	char buff[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_from = open(argv[1], O_RDONLY);
	if (f_from == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fto = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while ((rd = read(f_from, buff, BUFSIZ)) > 0)
		if (fto == -1 || (write(fto, buff, rd) != rd))
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	if (rd == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	clf = close(f_from);
	clt = close(fto);
	if (clf == -1 || clt == -1)
	{
		if (clf == -1)
			dprintf(STDERR_FILENO,
					"Error: Can't close fd %d\n", f_from);
		else if (clt == -1)
			dprintf(STDERR_FILENO,
					"Error: Can't close fd %d\n", fto);
		exit(100);
	}
	return (0);
}

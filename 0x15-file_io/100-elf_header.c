#include "main.h"

/**
 * main - copies the content of one file to another.
 * @argc: argument count.
 * @argv: Pointers to the arguments.
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int from, to, nrd, nwr;
	char *buffer;
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	nrd = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || nrd == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		nwr = write(to, buffer, nrd);
		if (to == -1 || nwr == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		nrd = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (nrd > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}

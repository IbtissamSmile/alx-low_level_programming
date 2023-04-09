#include "main.h"

/**
 * read_textfile - text file and prints the letters
 * @filename: filename.
 * @letters: the numbers of letters printed.
 * Return: the numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t nop, nrd, nwr;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	nop = open(filename, O_RDONLY);
	nrd = read(nop, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	if (nop == -1 || nrd == -1 || nwr == -1 || nwr != r)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(nop);

	return (nwr);
}

#include "main.h"
/**
 * create_file - creates a file
 * @filename: the filename.
 * @text_content: the content writed in the file.
 * Return: 1 on success. -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int nop, nwr, len = 0;
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	nop = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	nwr = write(nop, text_content, len);
	if (nop == -1 || nwr == -1)
		return (-1);
	close(nop);
	return (1);
}

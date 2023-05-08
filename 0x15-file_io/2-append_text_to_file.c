#include "main.h"
/**
 * append_text_to_file - the text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 * Return: 1 on file exists. -1 on fails does not exist
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int nop, nwr, len = 0;
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	nop = open(filename, O_WRONLY | O_APPEND);
	nwr = write(nop, text_content, len);
	if (nop == -1 || nwr == -1)
		return (-1);
	close(nop);
	return (1);
}

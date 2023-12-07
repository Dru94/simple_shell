#include "shell_header.h"

/**
 * custom_get_line - Read a line of input from a file descriptor
 *
 * @linePointer: Stores the address of the allocated buffer containing the line
 * @n: Stores the size of the allocated variable
 * @fd: The file descriptor from which to read the input
 *
 * Return: On success, the funciton returns the number of characters read,
 * excluding the newline characters.
 * On failure or if the end of the file is reached with no characters read,
 * it returns -1.
 */
ssize_t custom_get_line(char **linePointer, size_t *n, int fd)
{
	size_t pos = 0, buffer_size = BUFFER_SIZE;
	char ch, *buffer = (char *)malloc(buffer_size * sizeof(char));
	char *new_buffer;

	if (linePointer == NULL || n == NULL || buffer == NULL)
		return (-1);  /*Invalid arguments or memory allocation*/

	while (read(fd, &ch, 1) == 1)
	{
		if (pos + 1 >= buffer_size)
		{
			new_buffer = (char *)realloc(buffer,
					buffer_size + BUFFER_SIZE);
			if (new_buffer == NULL)
			{
				free(buffer);
				return (-1);  /*Memory allocation error*/
			}
			buffer = new_buffer;
			buffer_size += BUFFER_SIZE;
		}
		buffer[pos++] = ch;
		if (ch == '\n')
			break;
	}
	if (pos == 0)
	{
		free(buffer);
		return (-1);  /**No characters read*/
	}
	if (pos < buffer_size)
		buffer[pos] = '\0';
	else
		buffer[buffer_size - 1] = '\0';
	if (*linePointer != NULL)
		free(*linePointer);

	*linePointer = buffer;
	*n = pos;
	return (pos);
}

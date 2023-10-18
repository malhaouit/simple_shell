#include "shell.h"

/**
 * read_command_line - Reads the command from the user input
 * @buffer: The buffer where the command stored
 * @len: The length reserved by getline function for the buffer
 * @stream: From where we get the command (user input)
 *
 * Return: Number of characters if success, or -1 if it fails
 */
ssize_t read_command_line(char **buffer, size_t *len, FILE *stream)
{
	ssize_t n;
	*len = 0;
	*buffer = NULL;

	n = getline(buffer, len, stream);

	if (n == -1)
	{
		free(*buffer);
		return (-1);
	}

	return (n);
}

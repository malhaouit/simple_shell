#include "shell.h"

/**
 * print_env - Prints the current environment variables
 * @buffer: Buffer containing the command string
 *
 * Return: 1 if the buffer contains "env" or 0 if not
 */
int print_env(char *buffer)
{
	int i;

	if (_strcmp(buffer, "env\n") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(buffer);
		return (1);
	}
	else
		return (0);
}

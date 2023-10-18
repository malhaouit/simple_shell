#include "shell.h"

/**
 * exit_shell - Ends the custom shell.
 * @buffer: Buffer containing the command
 *
 * Return: 1 if buffer contains "exit" command, or -1 if not
 */
int exit_shell(char *buffer)
{
	if (_strcmp(buffer, "exit\n") == 0)
	{
		free(buffer);
		return (-1);
	}
	return (1);
}

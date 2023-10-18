#include "shell.h"

/**
 * handle_path - Handles the command from user input
 * @command: The command
 *
 * Return: The full_path of the command
 */
char *handle_path(char **command)
{
	char *path = NULL, *temp = NULL, *token = NULL, *full_path = NULL;
	struct stat st;
	int counter = 0;

	if (_strchr(command[0], '/') == NULL)
	{
		path = _getenv("PATH");
		temp = _strdup(path);
		token = strtok(temp, ":");

		while (token != NULL)
		{
			full_path = malloc(_strlen(token) + 1 + _strlen(command[0]) + 1);
			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, command[0]);

			if (stat(full_path, &st) == 0)
			{
				counter++;
				break;
			}
			free(full_path), full_path = NULL;
			token = strtok(NULL, ":");
		}
		if (!counter)
		{
			full_path = malloc(_strlen(command[0]) + 1);
			_strcpy(full_path, command[0]);
		}
		free(temp), temp = NULL;
	}
	else
	{
		full_path = malloc(_strlen(command[0]) + 1);
		_strcpy(full_path, command[0]);
	}

	return (full_path);
}

#include "shell.h"

/**
 * _getenv - Gets the value of an environement variable
 * @name: The name of the envirement variable
 *
 * Return: The value of the environement variable if success, or NULL if not
 */
char *_getenv(char *name)
{
	char *variable, *value, *token;
	int i = 0;

	if (name == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		variable = _strdup(environ[i]);

		if (variable != NULL)
		{
			token = strtok(variable, "=");

			if (token == NULL)
				return (NULL);

			if (_strcmp(name, token) == 0)
			{
				value = _strchr(environ[i], '=');

				if (value != NULL)
					value = value + 1;

				free(variable), variable = NULL;

				return (value);
			}
		}
		free(variable), variable = NULL;
		i++;
	}

	return (NULL);
}

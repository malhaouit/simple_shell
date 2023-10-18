#include "shell.h"

/**
 * tokenizer - Breaks a string into tokens
 * @buffer: The string to be tokenized
 *
 * Return: An array of tokens if successful, or NULL if not
 */
char **tokenizer(char *buffer)
{
	char *token = NULL;
	char **comd_tokens = NULL;

	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, " \t\n");
	if (token == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}

	comd_tokens = malloc(sizeof(char *) * COMD_SIZE);
	if (comd_tokens == NULL)
	{
		free(buffer);
		buffer = strtok(NULL, " \t\n");
		i++;
	}
	free(buffer), buffer = NULL;
	comd_tokens[i] = NULL;

	return (comd_tokens);
}

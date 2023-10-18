#include "shell.h"

/**
 * free_grid - Frees allocated memory for an array of strings (tokens)
 * @comd_tokens: The pointer to the allocated memory
 *
 * Return: Nothing
 */
void free_grid(char **comd_tokens)
{
	int i = 0;

	if (comd_tokens == NULL)
		return;

	while (comd_tokens[i] != NULL)
	{
		free(comd_tokens[i]);
		comd_tokens[i] = NULL;
		i++;
	}

	free(comd_tokens), comd_tokens = NULL;
}

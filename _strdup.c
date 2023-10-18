#include "shell.h"

/**
 * _strdup - Duplicates a string
 * @str: The string to be duplicated
 *
 * Return: The duplicated string
 */
char *_strdup(char *str)
{
	size_t length;
	char *duplicate;

	length = _strlen(str) + 1;

	duplicate = malloc(sizeof(char) * length);

	if (duplicate == NULL)
		return (NULL);

	_strcpy(duplicate, str);

	return (duplicate);
}

#include "shell.h"

/**
 * _strlen - calculates the length of a string.
 * @str: The string
 *
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

/**
 * _strcpy - Copies a string to another destination string buffer
 * @dest: The destination string
 * @src: The source string
 *
 * Return: Destination string containing the copy
 */
char *_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (dest);
}

/**
 * _strcat - Concatinates two strings
 * @dest: The string with which the source string will be concatinated
 * @src: The string to be concatinated
 *
 * Return: The concatinated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Difference value
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	char result;

	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			result = 0;
			i++;
		}

		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			break;
		}
	}
	return (result);
}

/**
 * _strchr - Locates a characetr in a string
 * @str: The pointer to the string
 * @c: The character to be found
 *
 * Return: A pointer to the found character or NULL if not
 */
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}

	if (c == '\0')
		return (str);

	return (NULL);
}



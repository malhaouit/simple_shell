#include "shell.h"

/**
 * display_prompt - Prints the prompt to the user
 * @prompt: The prompt to be displayed
 *
 * Return: Nothing
 */
void display_prompt(char *prompt)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 2);
}

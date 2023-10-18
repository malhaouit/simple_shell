#include "shell.h"

/**
 * main - Applies shell commands
 * @ac: The number of elements (external arguments) in argv
 * @argv: Array o strings including the name of the program itself
 * @env: Envirement variables
 *
 * Return: 0 if success, or other value if not
 */
int main(__attribute__((unused)) int ac, char **argv, char **env)
{
	ssize_t n;
	char *buffer = NULL;
	size_t len = 0;
	char **comd_tokens = NULL;
	int status = 0, is_exit, is_env;

	while (1)
	{
		display_prompt("$ ");

		n = read_command_line(&buffer, &len, stdin);

		if (n == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		is_exit = exit_shell(buffer);

		if (is_exit == -1)
			break;

		is_env = print_env(buffer);
		if (is_env == 1)
			continue;

		comd_tokens = tokenizer(buffer);

		if (comd_tokens == NULL)
			continue;

		status = execute_command(comd_tokens, argv, env);
	}
	return (status);
}


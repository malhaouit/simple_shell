#include "shell.h"

/**
* execute_command - Execute the command passed to the simple shell
* @command: The command to be executed
* @argv: Array of strings including the name of the program itself argv[0]
* @env: Envirement variables
*
* Return: Exit status if success, or -1 if not
*/
int execute_command(char **command, char **argv, char **env)
{
	pid_t child;
	int status;
	int exit_status;
	char *full_path = NULL;

	full_path = handle_path(command);

	child = fork();

	if (child == 0)
	{
		if (execve(full_path, command, env) == -1)
		{
		perror(argv[0]);
		free_grid(command);
		free(full_path), full_path = NULL;
		exit(127);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
		else
			exit_status = -1;
		free_grid(command);
		free(full_path), full_path = NULL;
	}
	return (exit_status);
}

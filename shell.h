#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define COMD_SIZE 1024

extern char **enivron;

void display_prompt(char *prompt);
ssize_t read_command_line(char **buffer, size_t *len, FILE *stream);
char **tokenizer(char *line);
void free_grid(char **array);
char *_getenv(char *name);
char *handle_path(char **command);
int exit_shell(char *buffer);
int print_env(char *buffer);
int execute_command(char **command, char **argv, char **env);

#endif

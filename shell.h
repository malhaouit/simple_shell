#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define COMD_SIZE 1024

extern char **environ;

void display_prompt(char *prompt);
ssize_t read_command_line(char **buffer, size_t *len, FILE *stream);
char **tokenizer(char *line);
void free_grid(char **array);
char *_getenv(char *name);
char *handle_path(char **command);
int exit_shell(char *buffer);
int print_env(char *buffer);
int execute_command(char **command, char **argv, char **env);

int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);

#endif

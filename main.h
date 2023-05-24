#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

ssize_t get_input(char **input, size_t *n);
void execute_command(char *args[], char *env[]);
int exit_shell(char *input);
int is_executable_found(const char *command);
void handle_input(char *command, char *env[]);
int is_executable_found(const char *command);
/* void search_command(char *command, char *env[]) */

#endif /* MAIN_H */

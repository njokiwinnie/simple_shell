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

#endif /* MAIN_H */

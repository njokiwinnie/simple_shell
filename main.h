#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define REPEAT 1
#define PROMPT "$ "

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command);

#endif /* MAIN_H */

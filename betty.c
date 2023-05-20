#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/**
 * main - betty compliant shell program
 *
 * Return: 0 if succcessful
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	char *token;
	int i;
	pid_t pid;

	pid = fork();

	while (1)
	{
		printf("$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		command[strcspn(command, "\n")] = '\0';

		token = strtok(command, " ");
		i = 0;

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}

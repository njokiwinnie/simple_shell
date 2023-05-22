/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <unistd.h> */ 
/* #include <sys/wait.h> */
#include "main.h"

/**
 * main - simpler shell
 *	argv: user input
 *	args: command arguement
 *	env: environment
 *
 * Return: Always 1.
 *
 */

int main(void)
{
	char *input = NULL;
	size_t buffsize = 0;
	ssize_t read;
	int status;
	char *args[] = {"NULL", NULL};
	char *env[] = {NULL};

	while (1)
	{
		printf("($) ");
		read = getline(&input, &buffsize, stdin);

		if (read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (input[read - 1] == '\n')
			input[read - 1] = '\0';
		printf("Recieved: %s\n", input);
		args[0] = input;
		pid_t child_pid;
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork Error");
			exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
			execve(args[0], args, env);

			perror("./shell Error");
			exit(EXIT_FAILURE);
		} else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	free(input);
	return (0);
}

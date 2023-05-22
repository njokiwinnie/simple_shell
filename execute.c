#include "main.h"

/**
 * execute_command - creates a new child process
 *	to run the input using execve
 * @args: The user input to run
 * @env: enviroment
 *
 * Return: 0.
 *
 */

void execute_command(char *args[], char *env[])
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork Error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(args[0], args, env);

		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}

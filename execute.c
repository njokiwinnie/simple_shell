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
		if (execve(args[0], args, env) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

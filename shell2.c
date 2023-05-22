#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	char argv[150];
	char *args[] = {"NULL", NULL};
	char *env[] = {NULL};
	int status;

	while (1)
	{
		printf("($) ");
		scanf("%s", argv);

		printf("Recieved: %s\n", argv);

		args[0] = argv;

		pid_t child_pid;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork Error");
			exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
			/* child process created */
			/* run execve on user input (argv) */

			execve(args[0], args, env);

			perror("./shell Error");
			sleep(3);
			exit(EXIT_FAILURE);
		} else
		{
			/* wait for new process above to finish */
			waitpid(child_pid, &status, 0);
		}
	}

	return (0);
}

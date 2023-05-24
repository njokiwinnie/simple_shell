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
	char *args[] = {NULL, NULL};
	char *token;
	int i = 0;
	char *env[] = {NULL};

	while (1)
	{
		input = NULL;
		i = 0;
		printf("($) ");
		read = get_input(&input, &buffsize);
		if (exit_shell(input))
		{
			exit(0);
		}

		if (read == -1)
		{
			perror("get_input");
			exit(EXIT_SUCCESS);
		}
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		token = strtok(input, " ");
		while (token != NULL && i < 8)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		execute_command(args, env);
	}
	free(input);
	return (0);
}

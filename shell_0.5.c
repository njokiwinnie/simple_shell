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
		/* GET USER INPUT AND STORE  */
		input = NULL;
		i = 0;
		/* CHECK VALUE STORED IN INPUT BEFORE LOOP STARTS */
		printf("($) ");
		read = get_input(&input, &buffsize);
		/* CHECK IF THE USER HAS TYPED EXIT */
		if (exit_shell(input))
		{
			printf("Bye! Bye! You're Exiting...\n");
			free(input);
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
		args[0] = input;
		execute_command(args, env);
	}
	/* AT THIS POINT WE CLEAR THE MEMORY ALLOCATED TO INPUT BY read EARLIER */
	free(input);
	return (0);
}

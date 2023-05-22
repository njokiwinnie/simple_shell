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
	char *args[] = {input, NULL};
	/* char *args[]; */
	char *token;
	int i = 0;
	char *env[] = {NULL};

	while (1)
	{
		input = NULL;
		printf("Current values of Input: %s\n", input);
		printf("($) ");
		read = get_input(&input, &buffsize);
		
		printf("Before IF 1 %s\n", input);
		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		if (read == -1)
		{
			perror("get_input");
			exit(EXIT_SUCCESS);
		}
		printf("Before IF 3 %s\n", input);
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		token = strtok(input, " ");
		printf("Before last WHILE %s\n", input);
		while (token != NULL && i < 4)
			{
				args[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
		printf("After WHILE loop: %s\n", input);
		args[i] = NULL;

		printf("Recieved: %s as input\n", input);
		/* args[0] = input; */
		execute_command(args, env);
	}
	free(input);
	return (0);
}

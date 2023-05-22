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
		/* GET USER INPUT AND STORE  */
		input = NULL;
		/* CHECK VALUE STORED IN INPUT BEFORE LOOP STARTS */
		printf("Current values of Input: %s\n", input);
		printf("($) ");
		read = get_input(&input, &buffsize);
		
		printf("Before IF 1 %s\n", input);
		/* CHECK IF THE USER HAS TYPED EXIT */

		if (exit_shell(input))
		{
			printf("Bye! Bye! You're Exiting...\n");
			sleep(2);
			free(input);
			exit(0);
		}

		if (read == -1)
		{
			perror("get_input");
			exit(EXIT_SUCCESS);
		}
		/* CHECK VALUE STORED IN INPUT BEFORE IF LOOP STARTS */
		printf("Before IF 3 %s\n", input);
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		token = strtok(input, " ");
		/* CHECK VALUE STORED IN INPUT BEFORE LOOP STARTS */
		printf("Before last WHILE %s\n", input);
		while (token != NULL && i < 4)
			{
				args[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
		/* CHECK VALUE STORED IN INPUT BEFORE LOOP STARTS */
		printf("After WHILE loop: %s\n", input);
		args[i] = NULL;
		/* CHECK VALUE STORED IN INPUT BEFORE LOOP STARTS */
		printf("Recieved: %s as input\n", input);
		/* args[0] = input; */
		execute_command(args, env);
	}
	/* AT THIS POINT WE CLEAR THE MEMORY ALLOCATED TO INPUT BY read EARLIER */
	free(input);
	return (0);
}

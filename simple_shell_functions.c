#include "main.h"

/**
 * is_executable_found - Check if input is executable
 * @command: input command for checking
 *
 * Return: 1 if the command is executable, 0 if not.
 */
int is_executable_found(const char *command)
{
	if (access(command, X_OK) == 0)
	return (1);
	return (0);
}

/**
 * handle_input - Manage the execution of user input
 * @input: The command to execute
 * @env: The environment variables
 */
void handle_input(char *input, char *env[])
{
	char *token;
	int i;
	char *args[] = {NULL, NULL};

	token = strtok(input, " ");
	args[0] = (char *)input;
	i = 0;

	while (token != NULL && i < 8)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	if (is_executable_found(input))
	{
		/* Pass the command to be  executed */
		execute_command(args, env);
	}
	else
	{
		printf("Command not found: %s\n", input);
	}
}

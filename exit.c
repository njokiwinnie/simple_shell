#include "main.h"

/**
 * exit_shell - check for user input of exit
 *	terminate the shell
 * @input: user input
 * Return: isExit.
 *
 */

int exit_shell(char *input)
{
	int isExit = 1;
	/* Remove the newline character from the input string */
	size_t input_length = strlen(input);

	if (input_length > 0 && input[input_length - 1] == '\n')
	{
		input[input_length - 1] = '\0';
	}

	/* handler to indicate if the input is equal to "exit" */

	for (int i = 0; input[i] != '\0' && i < 4; i++)
	{
		if (input[i] != "exit"[i])
		{
			isExit = 0;
			break;
		}
	}
	return (isExit);
}

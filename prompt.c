#include "main.h"

/**
 * get_input - Obtain input from the user
 * @input: store user input
 * @n: buffer
 *
 * Return: Always 1.
 */

ssize_t get_input(char **input, size_t *n)
{
	ssize_t read = getline(input, n, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			/* newline after Ctrl+D */
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	return (read);
}

#include "main.h"

/**
 * _getline - inputs into a buffer
 * @pr: input buffer
 * Return: buffer with user input
 */
char *_getline(FILE *pr)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, pr);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}

#include "main.h"

/**
 * free_all - frees malloc
 * @tokens: token array pointer
 * @path: path variable 
 * @line: input buffer pointer
 * @fullpath: path
 * @flag: flag mark
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - free double pointer
 * @array: double pointer to free
 * @length: length of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}


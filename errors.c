#include "main.h"

/**
 * errors - case error
 * @error: number of error on perror
 * Return: void
 */
void errors(int error)
{
	switch (error)
	{
	case 1: /* fork error to stderr */
		write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
		perror("Error");
		break;

	case 2: /*  execve error to stderr */
		perror("Error");
		break;

	case 3: /* malloc error to stderr */
		write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
		break;
	case 4: /* empty path error to stderr */
		write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
		break;

	default:
		return;
	}
}

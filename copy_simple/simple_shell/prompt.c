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
	return (getline(input, n, stdin));
}

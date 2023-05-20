#include <stdio.h>
#include <unistd.h>

/**
 * main - provides the prompt
 *
 * Return: Always 1.
 */

int main(void)
{
	/* length of possible input */
	char prompt[150];

	printf("$ ");
	scanf("%s", prompt);

	return (0);
}

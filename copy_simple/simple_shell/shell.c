#include <stdio.h>
#include <stdlib.h>
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
	/* int i = 0; */
	/* char argc; */

	printf("($) ");
	scanf("%s", prompt);
	printf("You have entered:\n%s\n", prompt);

	/* Finally, this makes a system call to execute the user input */
	system(prompt);

	return (0);
}

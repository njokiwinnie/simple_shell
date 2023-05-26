#include "main.h"

/**
 * execute_command - Execute the given command.
 * @command: The command to be executed.
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		/* char *args[] = {NULL, NULL}; */
		char *args[2];
		char *envp[] = {NULL}; /* Environment variable list */
		args[0] = command;
		args[1] = NULL;

		if(execve(command, args, envp) == -1)
		{
			/* If execve returns, means command execution failed */
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * main - Entry point of the shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char newline = '\n';
	ssize_t bytes_read;
	int interactive_mode = isatty(STDIN_FILENO);

	while (REPEAT)
	{
		if (interactive_mode)
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

		bytes_read = read(0, command, sizeof(command) - 1);
		
		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (bytes_read == 0)
		{
			/* Handle end of file (Ctrl+D) */
			write(1, &newline, 1);
			break;
		}

		/* Remove the newline character at the end of the command */
		command[bytes_read -1] = '\0';

		execute_command(command);
	}

	return (0);
}

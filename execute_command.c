#include "main.h"

/*
 * execute_command - Execute command with arguments using execvp system call
 *
 * args: Array of command arguments
 *
 * Returns: void
 *
 */
void execute_command(char **args)
{
	pid_t pid;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

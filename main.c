#include "main.h"

/*
 * main - main function to run shell
 *
 *
 * Returns: int
 *
 */

int main(void)
{
	char input[MAX_LENGTH_OF_INPUT];
	char *args[MAX_LENGTH_OF_INPUT / 2 + 1];
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		fgets(input, MAX_LENGTH_OF_INPUT, stdin);
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		input[strcspn(input, "\n")] = '\0';
		parse_input(input, args);

		if (args[0] == NULL)
		{
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(EXIT_FAILURE);
			}
		} else if
			(pid < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
		else
		{
			wait(NULL);
		}
	}
	return (EXIT_SUCCESS);
}

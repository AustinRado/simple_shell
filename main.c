#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH_OF_INPUT 1024

/*
 * main -takes no arguments and returns an integer
 *
 *
 * Returns - 0
 *
 */
int parse_input(char *input, char **args);

int main(void)
{
	char input[MAX_LENGTH_OF_INPUT];
	char *args[MAX_LENGTH_OF_INPUT / 2 + 1];
	pid_t pid;
	int arg;

	while (1)
	{
		printf("$ ");
		fgets(input, MAX_LENGTH_OF_INPUT, stdin);
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		input[strcspn(input, "\n")] = '\0';
		arg = parse_input(input, args);

		if (arg == 0)
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
			(pid > 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
	}
	return (EXIT_SUCCESS);
}

/*
 * parse_input - called to parse the user input and store in the args array
 *
 *
 */

int parse_input(char *input, char **args)
{
	int argc = 0;
	char *delim = " \t\r\n";
	char *token = strtok(input, delim);

	while (token != NULL)

	{
		args[argc++] = token;
		token = strtok(NULL, delim);
	}
	args[argc] = NULL;
	return (argc);
}

#include "main.h"

/*
 * parse_input - parses input string into an array of arguments
 * @input: input string
 * @args: array of arguments
 *
 * Return: void
 */

void  parse_input(char *input, char **args)
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
}


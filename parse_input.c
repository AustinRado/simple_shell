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
	char* token;
	int i = 0;

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
}

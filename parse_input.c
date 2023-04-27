#include "main.h"

/*
 * parse_input - parses input string into an array of arguments
 * @input: input string
 * @args: array of arguments
 *
 * Return: void
 */

#define MAX_ARGS 20
#define ARG_LEN 50

void  parse_input(char *input, char **args)
{
	int i = 0;

	char* token;
	size_t input_len = strlen(input);

	if (input_len > 0 && input[input_len - 1] == '\n')
	{
		input[input_len - 1] = '\0';
		input_len--;
	}

	token = strtok(input, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		strncpy(args[i], token, ARG_LEN);
		args[i][ARG_LEN - 1] = '\0';
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}

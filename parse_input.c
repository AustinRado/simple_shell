#include <string.h>

void parse_input(char *input, char **args)
{
	const char delim[] = " ";
	char *word = strtok(input, delim);
	int i = 0;

	while (word != NULL)
	{
		args[i] = word;
		i++;
		word = strtok(NULL, delim);
	}

	args[i] = NULL;
}

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
		execute_command(args);
	}
	return (EXIT_SUCCESS);
}

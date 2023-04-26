#include "main.h"

/***
 * read_input - Read input from standard input and return it as a string
 *
 *
 * Returns: char *
 */

char *read_input(void)
{
        char *input = NULL;
        size_t input_size = 0;
        ssize_t characters = getline(&input, &input_size, stdin);

        if (characters == -1)
        {
                perror("Failed to read input");
                exit(EXIT_FAILURE);
        }
        input[strcspn(input, "\n")] = '\0';

        return (input);
}

#include "main.h"

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - a function that prints the prompt to the user
 * Return void
*/
void display_prompt(void)
{
if (isatty(STDIN_FILENO))
{
{
printf("cisfun$ ");
fflush(stdout);
}
}
}


/**
 * main - function executes simple shell
 * Return: 0
*/
int main(void)
{
char input[MAX_INPUT_SIZE];

display_prompt();

while (fgets(input, sizeof(input), stdin))
{
printf("%s", input);

display_prompt();
}

return (0);
}

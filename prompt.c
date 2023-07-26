#include "main.h"
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

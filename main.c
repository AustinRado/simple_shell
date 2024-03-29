#include "main.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

/**
 * main - function executes simple shell
 * Return: 0
*/
int main(void)
{
char input[MAX_INPUT_SIZE];
char *token;
char *args[MAX_ARGS];
int arg_count = 0;


display_prompt();

while (fgets(input, sizeof(input), stdin))
{
input[strcspn(input, "\n")] = '\0';
token = strtok(input, " ");
while (token != NULL && arg_count < MAX_ARGS - 1)
{
args[arg_count] = token;
arg_count++;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (arg_count > 0 && strcmp(args[0], "cd") == 0)
{
cd_builtin(args);
}
else if (arg_count > 0 && strcmp(args[0], "exit") == 0)
{
exit_builtin();
break;
}
else
{
execute_external_command(args);
}
display_prompt();
}
return (0);
}


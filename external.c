#include "main.h"
/**
 * execute_external_command - function executes command in child processes
 * @args: An array of strings containing the command and its arguments.
 * Return void
*/
void execute_external_command(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{

if (execvp(args[0], args) == -1)
{
print_command_not_found_error(args[0]);
_exit(1);
}
}
else if (pid < 0)
{

perror("Error");
}
else
{
if (waitpid(pid, &status, WUNTRACED) == -1)
{
perror("Error");
}
}
}

#include "main.h"

/**
 * cd_builtin - function changes the working directory
 * @args: An array of strings containing command and arguments
 * Return: 0
 *
*/

int cd_builtin(char **args)
{
if (args[1] == NULL)
{
const char *home_dir = getenv("HOME");
if (home_dir == NULL)
{
print_chdir_error("cd");
return (1);
}
if (chdir(home_dir) != 0)
{
print_chdir_error("cd");
return (1);
}
}
else
{
if (chdir(args[1]) != 0)
{
print_chdir_error("cd");
return (1);
}
}

return (0);
}

/**
 * exit_builtin - a function that terminates the shell
 * Return: 0
 *
*/
int exit_builtin(void)
{
return (0);
}

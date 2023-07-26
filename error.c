#include "main.h"

/**
 * print_command_not_found_error - Prints error message for cmd not found.
 * @command: The command that was not found.
 * Return void
 */
void print_command_not_found_error(const char *command)
{
fprintf(stderr, "Error: Command not found: %s\n", command);
}

/**
 * print_chdir_error - Prints error message for changing directory failure.
 * @path: The path of the directory that could not be accessed.
 * Return void
 */

void print_chdir_error(const char *path)
{
perror(path);
}

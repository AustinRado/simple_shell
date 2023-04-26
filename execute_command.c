#include "main.h"

/*
 * execute_command - Execute command with arguments using execvp system call
 *
 * args: Array of command arguments
 *
 * Returns: void
 exit(EXIT_FAILURE);exit(EXIT_FAILURE);*
 */
void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			if (errno == ENOENT)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
			}
			else
			{
				perror(args[0]);
			}
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Failed to wait for child process");
		}
		else 
		{
			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
				if (exit_status != 0)
				{
					fprintf(stderr, "Command returned non-zero exit status %d\n", exit_status);
				}
			}
			else if (WIFSIGNALED(status))
			{
				int signal_number = WTERMSIG(status);
				fprintf(stderr, "Command terminated with signal %d (%s)\n", signal_number, strsignal(signal_number));
			}
			else
			{
				fprintf(stderr, "Command terminated abnormally\n");
			}
		}
	}
}

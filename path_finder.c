#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH (MAX_PATH_LENGTH + MAX_FILENAME_LENGTH + 1)

char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *token;
	char *path_component;
	char *command_path = (char*) malloc(MAX_COMMAND_LENGTH);
	

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set.\n");
		return NULL;
	}
	token = strtok(path, ":");

	while (token != NULL)
	{
		path_component = (char*) malloc(strlen(token) + 2 + strlen(command));
		sprintf(path_component, "%s/%s", token, command);

		if ((access(path_component, X_OK) == 0))
		{
			strncpy(command_path, path_component, MAX_COMMAND_LENGTH);
			free(path_component);
			return command_path;
		}

		free(path_component);
		token = strtok(NULL, ":");
	}
	free(command_path);
	
	return(NULL);
}

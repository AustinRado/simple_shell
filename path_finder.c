#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096

char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char *full_path = (char *) malloc(MAX_PATH_LENGTH * sizeof(char));

	while (dir != NULL)
	{
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}

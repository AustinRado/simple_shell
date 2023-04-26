#include "main.h"

/**
 * set_env - sets a new value for an environment variable or creates a new one
 * @envp: array of environment variables
 * @name: name of the variable to set
 * @value: value to set the variable to
 *
 * Return: 0 on success, -1 on failure
 */
int set_env(char **envp, const char *name, const char *value)
{
	char *new_var;
        size_t name_len, value_len, i;

        if (!name || !value)
	{
                return (-1);
	}
	
	name_len = strlen(name);
        value_len = strlen(value);
        new_var = malloc(name_len + value_len + 2);
        
	if (!new_var)
	{
		return (-1);
	}
	
	i = 0;

	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], name, name_len) == 0 && envp[i][name_len] == '=')
		{
			snprintf(new_var, name_len + value_len + 2, "%s=%s", name, value);
			free(envp[i]);
			envp[i] = new_var;
			return (0);
		}
		i++;
	}

	snprintf(new_var, name_len + value_len + 2, "%s=%s", name, value);

	i = 0;
	while (envp[i])
         i++;
	envp[i] = new_var;
	envp[i + 1] = NULL;
	return (0);
}

/**
 * unset_env - removes an environment variable
 * @envp: array of environment variables
 * @name: name of the variable to remove
 *
 * Return: 0 on success, -1 on failure
 *
 **/

int unset_env(char **envp, const char *name)
{
	size_t name_len, i, j;
	if (!name)
	{
		return (-1);
	}

	name_len = strlen(name);

	i = 0;
	 while (envp[i])
	 {
		 if (strncmp(envp[i], name, name_len) == 0 && envp[i][name_len] == '=')
		 {
			 free(envp[i]);
			 j = i;
			 while (envp[j])
			 {
				 envp[j] = envp[j + 1];
				 j++;
			 }
			 return (0);
		 }
		 i++;
	 }
	 return (-1);
}

/**
 * print_env - prints all environment variables
 * @envp: array of environment variables
 *
 * */

void print_env(char **envp)
{
	int i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

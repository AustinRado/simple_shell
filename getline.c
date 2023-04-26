#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 1024
#define BUFFER_INCREMENT 1024

/**
 *
 *
 *
 *
 *
 *
 *
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *new_ptr;
	size_t i = 0;
	int c;
	if (!lineptr || !n || !stream)
	{
		return (-1);
	}

	if (*lineptr == NULL || *n < 1)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i >= *n - 1)
		{
			*n += BUFFER_INCREMENT;
			new_ptr = realloc(*lineptr, *n);

			if (new_ptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_ptr;
		}
		(*lineptr)[i++] = c;
	}
	if (i == 0 && c == EOF)
	{
		return (-1);
	}
	(*lineptr)[i] = '\0';
	return (i);
}

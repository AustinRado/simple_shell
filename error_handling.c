#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error_handler(char *filename, int errcode)
{
	switch (errcode)
	{
		case 1:
			fprintf(stderr, "Error: Failed to open file '%s': %s\n", filename, strerror(errno));
			exit(1);
		case 2:
			fprintf(stderr, "Error: Failed to close file '%s': %s\n", filename, strerror(errno));
			exit(1);
	        default:
			fprintf(stderr, "Error: Unknown error occurred while processing file '%s'\n", filename);
			exit(1);}

}

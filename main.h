#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 256
#define MAX_LENGTH_OF_INPUT 1024

void  parse_input(char *input, char **args);
void execute_command(char **args);
void parse_input(char *input, char **args);
char *read_input(void);

/*size_t my_getline(char **lineptr, size_t *n, FILE *stream);*/

#endif /* MAIN.H */

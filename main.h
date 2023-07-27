#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(void);
int cd_builtin(char **args);
int exit_builtin(void);
void print_command_not_found_error(const char *command);
void print_chdir_error(const char *path);
void execute_external_command(char **args);


#endif

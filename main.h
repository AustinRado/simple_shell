#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void display_prompt(void);
int cd_builtin(char **args);
int exit_builtin(void);

#endif

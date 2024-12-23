#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


char* get_input(void);
void parse_input(char *input, char **args);
void execute(char **args);
void handle_fork(char **args);

#endif

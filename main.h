#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


char *get_line(void);
void parse_input(char *input);
void execute_command(char *cmd);

#endif

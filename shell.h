#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>



char *read_input(void);
char **parse_input(char *input);
void execute_command(char **args);
void handle_exit(void);
void handle_error(char *command);
char *find_in_path(char *command);

#endif


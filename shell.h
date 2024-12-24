#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define PROMPT "($) "
#define MAX_ARGS 100
char *read_input(void);
char **parse_input(char *input);
void fork_and_execute(char **args, char **env);
void handle_cd(char **args);
void handle_env(char **env);

#endif

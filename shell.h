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
void execute_command(char **args, char **env);
void handle_error(const char *cmd, const char *prog_name);
void search_in_path(char **args, char **env, char *path);
int main(int argc, char **argv, char **env);
void exit_shell(char **args);

#endif

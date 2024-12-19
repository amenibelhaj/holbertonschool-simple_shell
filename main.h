#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

ssize_t get_line(char **line, size_t *len);
char **parse_line(char *line);

void execute_line(char **args);

#endif

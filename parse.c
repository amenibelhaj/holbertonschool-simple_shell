#include "shell.h"

void parse_input(char *input, char **args)
{
    int i = 0;
    char *token;

    token = strtok(input, " \t\n");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

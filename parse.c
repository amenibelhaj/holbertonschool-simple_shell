#include "shell.h"
/**
 * parse_input - Parses the input string into an array of arguments.
 * @input: The input string to be parsed.
 *
 * Return: An array of strings (arguments) parsed from the input.
 */
char **parse_input(char *input)
{
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *token;
    int i = 0;

    if (args == NULL)
    {
        perror("malloc failed");
        exit(1);
    }

    token = strtok(input, " ");
    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return args;
}

#include "shell.h"

/**
 * parse_input - Tokenizes the input string into individual arguments.
 *
 * @input: The raw input string entered by the user.
 *
 * Return: A pointer to an array of strings containing the arguments.
 *         The array is null-terminated.
 */

char **parse_input(char *input)
{
char **args;
char *token;
int index = 0;

args = malloc(sizeof(char *) * MAX_ARGS);
if (!args)
{
perror("malloc failed");
exit(1);
}

token = strtok(input, " ");
while (token != NULL)
{
args[index] = token;
index++;
token = strtok(NULL, " ");
}
args[index] = NULL;
return (args);
}

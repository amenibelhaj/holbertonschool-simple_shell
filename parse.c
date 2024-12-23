#include "shell.h"
/**
 * parse_input - Tokenizes the input string into individual arguments.
 * @input: The raw input string entered by the user.
 *
 * Return: A pointer to an array of strings containing the arguments.
 *         The array is null-terminated.
 */
char **parse_input(char *input)
{
char **args = malloc(64 * sizeof(char *));
char *token = strtok(input, " \n");
int i = 0;

if (args == NULL)
{
perror("malloc failed");
exit(1);
}

while (token != NULL)
{
args[i] = token;
i++;
token = strtok(NULL, " \n");
}
args[i] = NULL;
return (args);
}

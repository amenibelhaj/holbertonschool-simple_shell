#include "main.h"

/**
 * parse_input - Processes the input string.
 * @input: A pointer to the string input.
 */
void parse_input(char *input)
{
    char *args[100];
    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;  

    execute_command(args);  
}

#include "shell.h"

/**
 * read_input - Reads a line of input from the user.
 *
 * @return: A string containing the input entered by the user.
 * NULL is returned if EOF (Ctrl+D) is encountered.
 */
char *read_input(void)
{
    char *input = NULL;
    size_t len = 0;

    if (getline(&input, &len, stdin) == -1)
    {
        if (feof(stdin))  
        {
            free(input);
            return (NULL);
        }
        perror("getline failed");
        free(input);
        exit(1);
    }

    return (input);
}

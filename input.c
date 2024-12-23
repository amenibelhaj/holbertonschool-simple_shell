#include "main.h"

/**
 * get_input - Function to read input from the user.
 * @input: Pointer to the input string buffer.
 * 
 * Return: The number of characters read.
 */
ssize_t get_input(char **input)
{
    size_t len = 0;
    ssize_t read;

    read = getline(input, &len, stdin);
    if (read == -1)
    {
        return -1;
    }
    (*input)[strcspn(*input, "\n")] = '\0'; 
    return read;
}

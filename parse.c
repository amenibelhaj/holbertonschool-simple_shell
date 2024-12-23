#include "main.h"

/**
 * parse_input - Processes a string input.
 * @input: A pointer to the string to be parsed.
 * Description: This function processes the given input string,
 * typically by parsing or manipulating its contents.
 */
void parse_input(char *input)
{
    size_t i; 
    
    /* Manually remove the newline character from the input string */
    for (i = 0; input[i] != '\0'; i++)  
    {
        if (input[i] == '\n')
        {
            input[i] = '\0';  /* Replace newline with null terminator */
            break;
        }
    }

    if (strlen(input) > 0)
    {
        execute_command(input);
    }
}

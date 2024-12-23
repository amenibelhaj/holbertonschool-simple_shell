#include "shell.h"

/**
 * main - The main entry point of the shell program.
 * @return: Always returns 0 (success).
 */

int main(void)
{
char *input;
    char **args;

    while (1)
    {
        printf("$ ");
        fflush(stdout); 
        input = read_input();
        if (input == NULL) 
        {
            break;
        }
        
        args = parse_input(input);
        if (args[0] == NULL)  
        {
            free(input);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)  
        {
            free(input);
            free(args);
exit(0);
}
else
{
execute_command(args); 
        }

        free(input);
        free(args);
    }

return (0);
}

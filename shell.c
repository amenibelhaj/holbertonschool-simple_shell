#include "shell.h"

int main(void)
{
    char *input;
    char *args[100];  

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);
        input = get_input();  

        if (input == NULL)
        {
            free(input);  
            continue;
        }

        parse_input(input, args);  
        if (args[0] == NULL)
        {
            free(input);  
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            free(input);  
            break;
        }

        execute(args);  
        free(input);  
    }

    return (0);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point of the program.
 * Description: Displays a prompt, waits for input, and executes commands.
 * Return: Always returns 0 to indicate successful execution.
 */
int main()
{
    char *input;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        input = get_line();

        if (input == NULL)
        {
            printf("\n"); 
            break;  
        }

        if (strcmp(input, "exit") == 0)
        {
            free(input);
            exit(0); 
        }

        parse_input(input);
        free(input);
    }

    return 0;  
}

#include "main.h"

/**
 * main - Entry point for the simple shell.
 * 
 * Return: Always 0 (success)
 */
int main(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("$ ");  
        read = getline(&input, &len, stdin);  
        if (read == -1)  
        {
            free(input);
            exit(0);
        }
        input[strcspn(input, "\n")] = '\0';  

        if (strlen(input) > 0) 
        {
            parse_input(input); 
        }
    }

    free(input);
    return 0;
}

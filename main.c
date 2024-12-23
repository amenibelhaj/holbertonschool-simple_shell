#include "main.h"

int main(void)
{
    char *input;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        input = get_line();
        if (input == NULL)
        {
            break; /* Handle EOF (Ctrl+D) */
        }

        if (strcmp(input, "exit") == 0)
        {
            free(input);
            exit(0);  /* Exit the shell */
        }

        parse_input(input); /* Process the input */
        free(input);        /* Free allocated memory */
    }
    return (0);
}

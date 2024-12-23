#include <stdio.h>
#include "shell.h"

char *get_input(void)
{
    char *input = NULL;
    size_t len = 0;

    if (getline(&input, &len, stdin) == -1)
    {
        if (input)
            free(input);
        return NULL;
    }

    return input;
}

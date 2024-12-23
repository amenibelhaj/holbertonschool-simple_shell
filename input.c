#include "shell.h"
char* get_input(void) {
    char *input = NULL;
    size_t len = 0;
    if (getline(&input, &len, stdin) == -1)
     {
        if (feof(stdin)) 
        {
            exit(0); 
        }
        perror("getline failed");
        exit(1);
    }
    input[strcspn(input, "\n")] = 0;

    return (input);
}

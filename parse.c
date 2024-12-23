#include "shell.h"


void parse_input(char *input, char **args) {
    int i = 0;
    char *token;

    
    token = strtok(input, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; 
}

#include "main.h"


#define PROMPT "$"

// Main loop for the shell
int main(void) {
    char *line = NULL;
    char **args = NULL;
    size_t len = 0;
    ssize_t nread;
    
    while (1) {
        // Display the prompt only if interactive
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, PROMPT, 2);
        }

        // Get input from the user
        nread = get_line(&line, &len);
        if (nread == -1) {
            if (feof(stdin)) {
                printf("\nExiting...\n");
                break;  // Exit on EOF (Ctrl+D)
            }
            perror("getline");
            continue;
        }

        // Parse the input into commands and arguments
        args = parse_line(line);

        // Execute the command
        execute_line(args);

        // Free the arguments array if dynamically allocated
        free(args);
    }

    free(line);
    return 0;
}

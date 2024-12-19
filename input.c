#include "main.h"

ssize_t get_line(char **lineptr, size_t *n) {
    ssize_t nread = getline(lineptr, n, stdin);
    if (nread == -1) {
        // Check if it's EOF (Ctrl+D)
        if (feof(stdin)) {
            return -1;
        }
        perror("getline"); // Handle errors in getline
        return -1;
    }
    return nread;
}

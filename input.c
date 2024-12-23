#include "main.h"

char *get_line(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL); /* End of file or error */
    }
    return (line);
}

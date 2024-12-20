#include "main.h"
/**
 * get_line - Reads a line of input from the user.
 * @return: A pointer to the input string, or NULL if an error occurs.
 */

char *get_line(void)
{
char *line = NULL;
size_t len = 0;
    
if (getline(&line, &len, stdin) == -1)
{
free(line);
return (NULL);
}
return (line);
}

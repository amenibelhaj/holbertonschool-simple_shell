#include "shell.h"
/**
 * read_input - Reads a line of input from the user.
 *
 * @return: null
 */
char *read_input(void)
{
char *input = NULL;
size_t len = 0;

if (getline(&input, &len, stdin) == -1)
{
if (feof(stdin))
{
free(input);
return (NULL);
}
perror("getline failed");
free(input);
exit(1);
}

return (input);
}

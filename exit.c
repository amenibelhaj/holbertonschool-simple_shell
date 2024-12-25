#include "shell.h"
/**
 * exit_shell - Exits the shell program
 * @args: An array of arguments passed to the shell (unused in this function)
 */
void exit_shell(char **args)
{
free(args);
exit(0);
}

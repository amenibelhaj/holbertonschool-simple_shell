#include "shell.h"
/**
 * exit_shell - Exits the shell program.
 *
 * Return: No return (terminates the shell program).
 */
void exit_shell(void)
{
exit(EXIT_SUCCESS);
}
/**
 * handle_error - Prints an error message when a command is not found.
 * @cmd: The command that could not be found.
 * @prog_name: The name of the program (typically the shell's name).
 */
void handle_error(const char *cmd, const char *prog_name)
{
fprintf(stderr, "%s: 1: %s: not found\n", prog_name, cmd);
}

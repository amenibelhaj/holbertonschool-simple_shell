#include "main.h"

/**
 * execute_command - Executes a single-word command.
 * @cmd: The command to execute.
 * Description: This function will attempt to execute the provided
 * command in a new child process.
 */
void execute_command(char *cmd)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork failed");
exit(1);
}

if (pid == 0)
{
char **argv = malloc(2 * sizeof(char *));
if (argv == NULL)
{
perror("malloc failed");
exit(1);
}
argv[0] = cmd;
argv[1] = NULL;

if (execve(cmd, argv, NULL) == -1)
{
perror("Command execution failed");
free(argv);
exit(1);
}
free(argv);
}
else
{
wait(NULL);
}}


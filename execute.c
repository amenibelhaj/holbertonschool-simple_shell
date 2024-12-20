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
if (execlp(cmd, cmd, (char *)NULL) == -1)
{
perror("Command execution failed");
exit(1);
}
}
else
{
wait(NULL);
}
}

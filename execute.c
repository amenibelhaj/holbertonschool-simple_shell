#include "main.h"
/**
 * execute_command - Executes a shell command.
 * @cmd: Command to be executed.
 * Description:
 * Forks a child process to execute the given command using execvp().
 * Displays error messages if fork or execvp fails.
 * Return: Nothing. Exits on error.
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

if (access(cmd, X_OK) == 0)
{
execve(cmd, &cmd, NULL);
}
else
{
perror(cmd);
exit(1);
}
}
else
{
wait(NULL);
}
}

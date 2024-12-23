#include "shell.h"

/**
 * fork_and_execute - Forks a new process and executes a command.
 * @args: The parsed arguments (command).
 * @env: The environment variables.
 */
void fork_and_execute(char **args, char **env)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror(args[0]);
exit(1);
}
}
else
{
wait(NULL);
}
}

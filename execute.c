#include "main.h"

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

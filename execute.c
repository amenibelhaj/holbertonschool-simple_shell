#include "main.h"
void execute_line(char **args)
{

pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(1);
}
else if (pid == 0)
{
char *cmd = args[0];
char *full_path = NULL;

if (cmd[0] != '/')
{
full_path = malloc(strlen("/bin/") + strlen(cmd) + 1);
if (!full_path)
{
perror("malloc");
exit(1);
}
strcpy(full_path, "/bin/");
strcat(full_path, cmd);

            
if (access(full_path, X_OK) == 0)
{
if (execve(full_path, args, NULL) == -1)
{
perror(args[0]);
exit(1);
}}
else
{
perror(cmd);
exit(1);
}
free(full_path);
}
else
{
if (execve(cmd, args, NULL) == -1)
{
perror(args[0]);
exit(1);
}}
}
else
{
waitpid(pid, NULL, 0);
}}

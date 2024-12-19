#include "main.h"

void execute_line(char **args)
{
pid_t pid;
if (args[0] != NULL && strcmp(args[0], "exit") == 0)
{
exit(0);
}
if (args[0] != NULL && strcmp(args[0], "env") == 0)
{
extern char **environ;
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
return;
}
pid = fork();
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
char *path_env = getenv("PATH");
if (path_env != NULL)
{
char *path = strtok(path_env, ":");
while (path != NULL)
{
full_path = malloc(strlen(path) + strlen(cmd) + 2);
if (!full_path)
{
perror("malloc");
exit(1);
}
strcpy(full_path, path);
strcat(full_path, "/");
strcat(full_path, cmd);
if (access(full_path, X_OK) == 0)
{
if (execve(full_path, args, NULL) == -1)
{
perror(args[0]);
free(full_path);
exit(1);
}}
free(full_path);
path = strtok(NULL, ":");
}
}
perror(cmd);
exit(1);
}
else
{
if (execve(cmd, args, NULL) == -1)
{
perror(args[0]);
exit(1);
}}}
else
{
waitpid(pid, NULL, 0);
}}

#include "shell.h"

/**
 * search_in_path - Searches for a command in the directories listed in PATH.
 * @args: An array of arguments passed to the command
 *(where args[0] is the command).
 * @env: The environment variables for the current process.
 * @path: The PATH environment variable,
 * containing a list of directories to search in.
 */
void search_in_path(char **args, char **env, char *path)
{
pid_t pid;
char *cmd_path;
char *dir;
struct stat st;
cmd_path = malloc(1024);
if (cmd_path == NULL)
{
perror("malloc failed");
exit(1);
}
dir = strtok(path, ":");
while (dir != NULL)
{
snprintf(cmd_path, 1024, "%s/%s", dir, args[0]);
if (stat(cmd_path, &st) == 0 && st.st_mode & S_IXUSR)
{
pid = fork();
if (pid == -1)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
if (execve(cmd_path, args, env) == -1)
{
perror("execve failed");
exit(1);
}}
else
{
wait(NULL);
free(cmd_path);
return;
}}
dir = strtok(NULL, ":");
}
handle_error(args[0], args[0]);
free(cmd_path);
}

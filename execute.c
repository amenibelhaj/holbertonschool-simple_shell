#include "shell.h"
/**
 * execute_command - Executes a command by forking a process and using execve.
 * @args: An array of arguments (command and its parameters).
 * @env: An array of environment variables.
 */
void execute_command(char **args, char **env)
{
pid_t pid;
char *path = NULL;
struct stat st;

if (args[0][0] == '/')
{
if (stat(args[0], &st) == 0 && st.st_mode & S_IXUSR)
{
pid = fork();
if (pid == -1)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror("execve failed");
exit(1);
}}
else
{
wait(NULL);
return;
}}
else
{
handle_error(args[0], args[0]);
return; }}
path = getenv("PATH");
if (path == NULL)
{
handle_error(args[0], args[0]);
return; }
search_in_path(args, env, path);
}

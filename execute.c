#include "shell.h"
/**
 * execute_command - Executes a command by searching in
 * directories listed in PATH or using an absolute/relative path
 * @args: An array of command arguments (args[0] is the command)
 * Return: None
 */
void execute_command(char **args)
{
char *path = NULL;
pid_t pid = fork();

if (pid == 0)
{
path = find_in_path(args[0]);
if (path == NULL)
{
handle_error(args[0]);
exit(1);
}
if (execve(path, args, NULL) == -1)
{
handle_error(args[0]);
exit(1);
}}
else if (pid > 0)
{
wait(NULL);
}
else
{
perror("fork failed");
}}
void handle_exit(void)
{
exit(0);
}

void handle_error(char *command)
{
fprintf(stderr, "No such file or directory: %s\n", command);
}
char *find_in_path(char *command)
{
char *path_env = getenv("PATH");
char *token = strtok(path_env, ":");
char *command_path = malloc(1024);
if (command_path == NULL)
{
perror("malloc failed");
exit(1);
    }
while (token != NULL)
{
sprintf(command_path, "%s/%s", token, command);
if (access(command_path, X_OK) == 0)
{
return (command_path);
}
token = strtok(NULL, ":");
}
free(command_path);
return (NULL);
}

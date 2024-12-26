#include "shell.h"
/**
 * handle_cd - Changes the current directory.
 * @args: The arguments passed to the command (the directory to change to).
 */
void handle_cd(char **args)
{
if (args[1] == NULL)
{
char *home = getenv("HOME");
if (home == NULL)
{
perror("cd: HOME not set");
return; }
if (chdir(home) != 0)
{
perror("cd"); }}
else
{
if (chdir(args[1]) != 0)
{
perror("cd");
}}}
/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to find.
 * Return: Pointer to the value of the environment variable,
 * or NULL if not found.
 */
char *_getenv(const char *name)
{
int i = 0;
char *token, *copy_env;
while (environ[i] != NULL)
{
copy_env = strdup(environ[i]);
if (!copy_env)
return (NULL);
token = strtok(copy_env, "=");
if (token && strcmp(token, name) == 0)
{
token = strtok(NULL, "=");
free(copy_env);
return (token ? strdup(token) : NULL);
}
free(copy_env);
i++; }
return (NULL); }

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
 * handle_env - Handles the `env` built-in command
 * @env: The environment variables
 *
 * Return: None
 */
void handle_env(char **env)
{
int i;
for (i = 0; env[i]; i++)
printf("%s\n", env[i]);
}

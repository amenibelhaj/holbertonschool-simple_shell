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
 * handle_env - Prints the environment variables.
 * @env: The environment variables array.
 */
void handle_env(char **env)
{
int i = 0;

while (env[i] != NULL)
{
printf("%s\n", env[i]);
i++;
}}
/**
 * handle_error - Prints an error message when a command is not found.
 * @cmd: The command that could not be found.
 * @prog_name: The name of the program (typically the shell's name).
 */
void handle_error(const char *cmd, const char *prog_name)
{
fprintf(stderr, "%s: 1: %s: not found\n", prog_name, cmd);
}

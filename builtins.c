#include "shell.h"
/**
 * handle_cd - Changes the current directory of the shell process.
 * @args: A pointer to an array of strings representing the command
 * and its arguments. The second argument, if provided, is the
 * directory to change to. If no argument is provided, the function
 * attempts to change to the user's HOME directory.
 */
void handle_cd(char **args)
{
if (args[1] == NULL)
{
char *home = getenv("HOME");
if (home == NULL)
{
perror("cd: HOME not set");
return;
}
if (chdir(home) != 0)
{
perror("cd");
}
}
else
{
if (chdir(args[1]) != 0)
{
perror("cd");
}
}
}
/**
 * handle_env - Prints the current environment variables.
 * @env: A pointer to an array of strings
 * representing the environment
 *variables.
 *
 * Description:
 * This function iterates through the `env` array
 * and prints each environment
 * variable to the standard output (stdout)
 * Each environment variable is
 * printed on a new line.
 */
void handle_env(char **env)
{
int i = 0;

while (env[i] != NULL)
{
printf("%s\n", env[i]);
i++;
}
}

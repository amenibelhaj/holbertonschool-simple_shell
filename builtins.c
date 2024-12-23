#include "shell.h"


/**
 * handle_cd - Changes the current directory.
 * @args: The arguments passed to the command (the directory to change to).
 */
void handle_cd(char **args)
{
    if (args[1] == NULL)  // No argument provided, go to home directory
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
    else  // Change to the directory provided
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
        }
    }
}

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
    }
}

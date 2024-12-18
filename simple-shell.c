#include "shell.h"
/**
 * find_command_in_path - Searches for a command in the directories
 * listed in PATH.
 * @command: The command to search for.
 *
 * This function iterates over directories in the PATH environment variable,
 * builds a full path for the command, and checks if the command exists in any
 * of the directories. If the command is found
 * it returns the full path; otherwise,NULL.
 *
 * Return: The full path of the command if found, NULL if not found.
 */
char *find_command_in_path(char *command)
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");
char *full_path = NULL;

while (dir != NULL)
{
full_path = malloc(strlen(dir) + strlen(command) + 2);
if (full_path == NULL)
{
perror("malloc");
exit(1);
}
sprintf(full_path, "%s/%s", dir, command);

if (access(full_path, F_OK) == 0)
{
free(path_copy);
return (full_path);
}

free(full_path);
full_path = NULL;
dir = strtok(NULL, ":");
}

free(path_copy);
return (NULL);
}

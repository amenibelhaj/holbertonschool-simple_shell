#include "main.h"

void execute_command(char *args[])
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        if (args[0][0] != '/')
        {
            char *path = getenv("PATH");
            char *directories = strtok(path, ":");
            char full_path[1024];

            while (directories != NULL)
            {
                snprintf(full_path, sizeof(full_path), "%s/%s", directories, args[0]);

                if (access(full_path, X_OK) == 0)
                {
                    execve(full_path, args, NULL);
                    break;
                }

                directories = strtok(NULL, ":");
            }
        }

        if (execve(args[0], args, NULL) == -1)
        {
            perror(args[0]);
            exit(1);
        }
    }
    else
    {
        wait(NULL);
    }
}

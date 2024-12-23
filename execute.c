#include "shell.h"

void execute(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path = NULL;
    char *path = getenv("PATH");
    char *token;
    struct stat st;

    if (args[0] == NULL)
        return;

    pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        if (args[0][0] == '/')
        {
            if (execve(args[0], args, NULL) == -1)
            {
                perror("execve failed");
                exit(1);
            }
        }
        else
        {
            token = strtok(path, ":");
            while (token != NULL)
            {
                cmd_path = malloc(strlen(token) + strlen(args[0]) + 2);
                if (cmd_path == NULL)
                {
                    perror("malloc failed");
                    exit(1);
                }
                strcpy(cmd_path, token);
                strcat(cmd_path, "/");
                strcat(cmd_path, args[0]);

                if (stat(cmd_path, &st) == 0 && (st.st_mode & S_IXUSR))
                {
                    if (execve(cmd_path, args, NULL) == -1)
                    {
                        perror("execve failed");
                        free(cmd_path);
                        exit(1);
                    }
                }

                free(cmd_path);
                token = strtok(NULL, ":");
            }
            perror("Command not found");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
}

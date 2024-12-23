#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void execute(char **args) {
    pid_t pid;
    int status;
    char *path = NULL;
    char *cmd_path = NULL;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    path = getenv("PATH");
    if (path != NULL) {
        char *dir = strtok(path, ":");

        while (dir != NULL) {
            cmd_path = malloc(strlen(dir) + strlen(args[0]) + 2);
            if (cmd_path == NULL) {
                perror("malloc");
                exit(1);
            }
            strcpy(cmd_path, dir);
            strcat(cmd_path, "/");
            strcat(cmd_path, args[0]);

            if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) == 0) {
                break;
            }

            free(cmd_path);
            cmd_path = NULL;

            dir = strtok(NULL, ":");
        }
    }

    if (cmd_path == NULL) {
        fprintf(stderr, "execve failed: No such file or directory\n");
        return;
    }


    pid = fork();

    if (pid == -1) {
        perror("Error in fork");
        exit(1);
    }

    if (pid == 0) {
        if (execve(cmd_path, args, NULL) == -1) {
            perror("Error in execve");
            free(cmd_path);
            exit(1);
        }
    } else {
        wait(&status);
        free(cmd_path);
    }
}

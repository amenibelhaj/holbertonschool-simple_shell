#include "main.h"

void execute_command(char *cmd)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        /* Child process */
        char *argv[2];  /* Declare the argument array */

        argv[0] = cmd;  /* Assign the command */
        argv[1] = NULL; /* Null-terminate the array */

        if (execve(cmd, argv, NULL) == -1)
        {
            perror(cmd);
            exit(1);
        }
    }
    else
    {
        /* Parent process */
        wait(NULL);  /* Wait for the child process to terminate */
    }
}

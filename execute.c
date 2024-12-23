#include "main.h"
#include <sys/wait.h>  
#include <unistd.h>    
#include <stdlib.h>    

/**
 * execute_command - Executes a single-word command.
 * @cmd: The command to execute.
 * Description: This function attempts to execute the provided
 * command in a new child process.
 */
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
        if (execve(cmd, &cmd, NULL) == -1)
        {
            perror(cmd); 
            exit(1);  
        }
    }
    else  
    {
        wait(NULL);  
    }
}

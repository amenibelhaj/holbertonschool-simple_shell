#include "shell.h"

void handle_fork(char **args) 
{
    pid_t pid = fork(); 

    if (pid == -1) 
    {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0)
     { 
        if (execve(args[0], args, NULL) == -1)
         {
            perror("execve failed");
            exit(1);
        }
    } else 
    {  
        
        wait(NULL);
    }
}

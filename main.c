#include "shell.h"

int main(void)
 {
    char *input;
    char *args[100]; 

    while (1) {
      
        write(STDOUT_FILENO, "$ ", 2); 
        input = get_input();
        if (input == NULL)
         {
            free(input); 
            break;
        }

    
        parse_input(input, args);


        execute(args);

    
        free(input);
    }

    return 0;
}
